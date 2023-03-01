package com.example.binder.client.java;

import android.content.ComponentName;
import android.content.Context;

import com.example.binder.common.ServiceConnectionEx;


public class Example {

	public static ServiceConnectionEx
	createJavaServiceConnection(Context context) {
		ComponentName componentName = new ComponentName(
				"com.example.binder.service.java",
				"com.example.binder.service.java.MyService"
		);
		return new ServiceConnectionEx(context, componentName);
	}


	public static ServiceConnectionEx
	createNativeServiceConnection(Context context) {
		ComponentName componentName = new ComponentName(
				"com.example.binder.service.ndk",
				"com.example.binder.service.ndk.MyService"
		);
		return new ServiceConnectionEx(context, componentName);
	}

}
