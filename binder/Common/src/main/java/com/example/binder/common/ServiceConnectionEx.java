package com.example.binder.common;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Build;
import android.os.ConditionVariable;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.util.Log;

import com.example.binder.IMyService;


public class ServiceConnectionEx {
	private final Context mContext;
	private final ComponentName mServiceName;

	private IMyService mService = null;
	private volatile boolean mIsConnecting = false;
	private volatile boolean mIsConnected = false;
	private final ConditionVariable mWaitLock = new ConditionVariable();


	public ServiceConnectionEx(Context context, ComponentName serviceName) {
		mContext = context;
		mServiceName = serviceName;
	}


	public IMyService getService() {
		// Waits for service connection
		while (!mIsConnected && mIsConnecting) {
			mWaitLock.block();
		}
		return mIsConnected ? mService : null;
	}


	public void bindService() {
		if (mIsConnected || mIsConnecting) return;
		mIsConnecting = true;

		try {
			Intent intent = new Intent();
			intent.setComponent(mServiceName);

			if (!mContext.bindService(intent, mServiceConnection, Context.BIND_AUTO_CREATE)) {
				mIsConnecting = false;
				Log.e(Constants.TAG, "[App] [java] bindServiceFailed. " + "Name: " + mServiceName);
			}

			// bindService timeout
			if (Build.VERSION.SDK_INT < Build.VERSION_CODES.P) {
				new Handler(Looper.getMainLooper()).postDelayed(() -> {
					if (mIsConnecting) {
						Log.e(Constants.TAG, "[App] [java] bindServiceTimeout. " + "Name: " + mServiceName);
						mContext.unbindService(mServiceConnection);
						mIsConnecting = false;
					}
				}, 30000);
			}
		} catch (Throwable e) {
			mIsConnecting = false;
			throw e;
		}
	}


	public void unbind() {
		if (!mIsConnected) return;
		Log.d(Constants.TAG, "[App] [java] unbindService. " + "Name: " + mServiceName);

		mIsConnected = false;
		mService = null;
		mContext.unbindService(mServiceConnection);
	}




	/////////////////////////////////////////////////////////////////////////////////
	//
	//    ServiceConnection
	//

	private final ServiceConnection mServiceConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName name, IBinder binder) {
			Log.d(Constants.TAG, "[App] [java] onServiceConnected. " + "Name: " + name + ", Binder: " + binder);

			mService = IMyService.Stub.asInterface(binder);
			mIsConnected = true;
			mIsConnecting = false;
			mWaitLock.open();
		}

		@Override
		public void onServiceDisconnected(ComponentName name) {
			Log.d(Constants.TAG, "[App] [java] onServiceDisconnected. " + "Name: " + name);

			mIsConnected = false;
			mIsConnecting = false;
			mService = null;
		}

		@Override
		public void onBindingDied(ComponentName name) {
			Log.d(Constants.TAG, "[App] [java] onBindingDied. " + "Name: " + name);

			mIsConnected = false;
			mIsConnecting = false;
			mService = null;
		}

		@Override
		public void onNullBinding(ComponentName name) {
			Log.d(Constants.TAG, "[App] [java] onNullBinding. " + "Name: " + name);

			mIsConnected = false;
			mIsConnecting = false;
			mService = null;
		}
	};

	//
	//    ServiceConnection
	//
	/////////////////////////////////////////////////////////////////////////////////


}