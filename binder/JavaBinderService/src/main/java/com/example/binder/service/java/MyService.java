package com.example.binder.service.java;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

import com.example.binder.common.Constants;


public class MyService extends Service {
	private IBinder mBinder;


	@Override
	public void onCreate() {
		super.onCreate();
		mBinder = new MyServiceBinder();
	}

	@Override
	public IBinder onBind(Intent intent) {
		Log.d(Constants.TAG, "[MyService] [java] A client binds the service");
		return mBinder;
	}

	@Override
	public boolean onUnbind(Intent intent) {
		Log.d(Constants.TAG, "[MyService] [java] A client unbinds the service");
		return super.onUnbind(intent);
	}

}