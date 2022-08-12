package com.example.binder.common;

import android.util.Log;


public class Factory {

	private static final Thread.UncaughtExceptionHandler UncaughtExceptionHandler = (t, e) -> Log.e(Constants.TAG, "uncaughtException", e);


	public static Thread newDaemonThread(Runnable runnable) {
		Thread thread = new Thread(runnable);
		thread.setDaemon(true);
		thread.setUncaughtExceptionHandler(UncaughtExceptionHandler);
		return thread;
	}

}
