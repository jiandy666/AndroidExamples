package com.example.binder.service.ndk;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

import com.example.binder.common.Constants;


public class MyService extends Service {
	static {
		System.loadLibrary("ndk");
	}


	private IBinder mBinder;


	@Override
	public void onCreate() {
		super.onCreate();

		mBinder = null;

		if (null == mBinder) {
			Log.w(Constants.TAG, "[MyService] [ndk] Binder is null");
		} else {
			Log.d(Constants.TAG, "[MyService] [ndk] Binder is ready");
		}
	}


	@Override
	public IBinder onBind(Intent intent) {
		Log.d(Constants.TAG, "[MyService] [ndk] A client binds the service");

		return mBinder;
	}


	@Override
	public boolean onUnbind(Intent intent) {
		Log.d(Constants.TAG, "[MyService] [ndk] A client unbinds the service");

		return super.onUnbind(intent);
	}




	/////////////////////////////////////////////////////////////////////////////////
	//
	//    Native
	//

	public native IBinder createServiceBinder();

	//
	//    Native
	//
	/////////////////////////////////////////////////////////////////////////////////

}
