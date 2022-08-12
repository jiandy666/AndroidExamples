package google.breakpad;


import android.util.Log;


public class BreakpadInit {
	private static final String TAG = "AndroidZ.Breakpad";

	static {
		System.loadLibrary("androidz-breakpad");
	}


	public static void init(String path) {
		check();
		initNative(path);
	}

	private static native void initNative(String path);


	private static void check() {
		Log.i(TAG, "init");

		// check arch
		String arch = System.getProperty("os.arch");
		Log.i(TAG, "Arch: " + arch);
		if ( "i686".equals(arch) ) {
			Log.w(TAG, "Breakpad may not working on i686 platform, otherwise build by ndk 16 and gcc toolchain");
		}
	}

}
