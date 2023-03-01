## Using `aidl` of sdk build-tools

* `aidl` path 

  `<SDK>/build-tools/<version>/aidl`

* test file `IMyInterface.aidl`

  ```java
  interface IMyInterface {
      void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat, double aDouble, String aString);
  }
  ```

  

### 1. java from `aidl`

* generate `.java`

  ```bash
  aidl IMyInterface.aidl
  ```

* `.java` structure

  *see code*



### 2. cpp from `.aidl` 

* generate `.cpp`

  ```bash
  aidl --lang=ndk -o . -h . IMyInterface.aidl
  ```

* file structure

  *see code*
