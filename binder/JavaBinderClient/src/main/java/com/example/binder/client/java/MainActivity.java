package com.example.binder.client.java;

import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.binder.IMyService;
import com.example.binder.common.Constants;
import com.example.binder.common.Factory;
import com.example.binder.common.ServiceConnectionEx;


public class MainActivity extends AppCompatActivity {

	private TextView mTextView;

	private final ServiceConnectionEx mJavaServiceConnection   = Example.createJavaServiceConnection(this);
	private final ServiceConnectionEx mNativeServiceConnection = Example.createNativeServiceConnection(this);


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		mTextView = findViewById(R.id.text);
	}


	@Override
	protected void onResume() {
		super.onResume();

		talkToService(mJavaServiceConnection, "[ToJavaService] ");
		talkToService(mNativeServiceConnection, "[ToNdkService]  ");
	}


	@Override
	protected void onStop() {
		mJavaServiceConnection.unbind();
		mNativeServiceConnection.unbind();

		super.onStop();
	}


	private void message(String text) {
		runOnUiThread(() -> mTextView.append("\n" + text));
	}


	private void talkToService(ServiceConnectionEx connection, String msgPrefix) {
		connection.bindService();
		Factory.newDaemonThread(() -> {
			message(msgPrefix + "Waiting to talk to IMyService...");

			final IMyService service = connection.getService();
			if (service == null) {
				message(msgPrefix + "IMyService is null");
				return;
			}

			try {
				Log.d(Constants.TAG, "[App] [java] IMyInterface.basicTypes");
				service.basicTypes(2022, 65535000, true, 3.14f, 3.141592653589793238, "Hello, World!");
			} catch (RemoteException e) {
				Log.e(Constants.TAG, "[App] [java] Exception when invoking IMyService.basicTypes" + e.getMessage());
				e.printStackTrace();
			}

			message(msgPrefix + "Talked to IMyService. ");
		}).start();
	}

}