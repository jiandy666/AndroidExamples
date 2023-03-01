package com.example.binder.service.java;

import android.os.RemoteException;
import android.util.Log;

import com.example.binder.IMyService;
import com.example.binder.common.Constants;


public class MyServiceBinder extends IMyService.Stub {

	@Override
	public void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat, double aDouble, String aString) throws RemoteException {
		String str = "[MyService] [java] basicTypes : " +
				"int=" + anInt +
				", long=" + aLong +
				", boolean=" + aBoolean +
				", float=" + aFloat +
				", double=" + aDouble +
				", string=" + aString;
		Log.d(Constants.TAG, str);
	}

}
