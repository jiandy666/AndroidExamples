package com.example.binder.client.java;

import android.content.ComponentName;
import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.binder.common.Constants;
import com.example.binder.common.Factory;
import com.example.binder.common.IMyInterface;
import com.example.binder.common.ServiceConnectionEx;


public class MainActivity extends AppCompatActivity {

	private TextView mTextView;


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		mTextView = findViewById(R.id.text);
	}


	@Override
	protected void onResume() {
		super.onResume();

		talkToJavaService();
		talkToNdkService();
	}


	@Override
	protected void onPause() {
		mJavaServiceConnection.unbind();
		mNdkServiceConnection.unbind();

		super.onPause();
	}




	/////////////////////////////////////////////////////////////////////////////////
	//
	//    Procedures: talkToJavaService
	//

	private final ComponentName mJavaServiceName = new ComponentName("com.example.binder.service.java", "com.example.binder.service.java.MyService");
	private final ServiceConnectionEx mJavaServiceConnection = new ServiceConnectionEx(this, mJavaServiceName);


	private void talkToJavaService() {
		mJavaServiceConnection.bindService();
		Factory.newDaemonThread(talkToJavaServiceRunnable).start();
	}

	Runnable talkToJavaServiceRunnable = () -> {
		showMessage("Waiting to talk to IMyService...");

		final IMyInterface service = mJavaServiceConnection.getService();

		try {
			Log.d(Constants.TAG, "[App] [java] IMyInterface.basicTypes");
			service.basicTypes(2022, 65535000, true, 3.14f, 3.141592653589793238, "Hello, World!");
		} catch (RemoteException e) {
			Log.e(Constants.TAG, "[App] [java] Exception when invoking IMyService.basicTypes" + e.getMessage());
			e.printStackTrace();
		}

		showMessage("Talked to IMyService. ");
	};

	//
	//    Procedures: talkToJavaService
	//
	/////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////
	//
	//    Procedures: talkToJavaService
	//

	private final ComponentName mNdkServiceName = new ComponentName("com.example.binder.service.ndk", "com.example.binder.service.ndk.MyService");
	private final ServiceConnectionEx mNdkServiceConnection = new ServiceConnectionEx(this, mNdkServiceName);


	private void talkToNdkService() {
		mNdkServiceConnection.bindService();

		Factory.newDaemonThread(talkToNdkServiceRunnable).start();
	}

	Runnable talkToNdkServiceRunnable = () -> {
		showMessage("Waiting to talk to IMyService...");

		final IMyInterface service = mNdkServiceConnection.getService();

		try {
			Log.d(Constants.TAG, "[App] [java] IMyInterface.basicTypes");
			service.basicTypes(2022, 65535000, true, 3.14f, 3.141592653589793238, "Hello, World!");
		} catch (RemoteException e) {
			Log.e(Constants.TAG, "[App] [java] Exception when invoking IMyService.basicTypes" + e.getMessage());
			e.printStackTrace();
		}

		showMessage("Talked to IMyService. ");
	};

	//
	//    Procedures: talkToJavaService
	//
	/////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////
	//
	//    UI
	//

	private void showMessage(String text) {
		runOnUiThread(() -> mTextView.setText(text));
	}

	//
	//    UI
	//
	/////////////////////////////////////////////////////////////////////////////////

}