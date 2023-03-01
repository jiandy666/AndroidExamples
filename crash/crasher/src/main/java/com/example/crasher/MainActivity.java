package com.example.crasher;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

import java.io.File;

import google.breakpad.BreakpadInit;


public class MainActivity extends Activity {
	static {
		System.loadLibrary("ndk");
	}

	private native static void crash();


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// init Breakpad
		File crashDir = getDir("crash", MODE_PRIVATE);
		crashDir.mkdirs();
		BreakpadInit.init(crashDir.getAbsolutePath());

		findViewById(R.id.button1).setOnClickListener(v -> crash());

		findViewById(R.id.button2).setOnClickListener(v -> {
			Log.e("Example.Crasher", "we are going to crashing...");
			throw new RuntimeException("crash example");
		});
	}

}