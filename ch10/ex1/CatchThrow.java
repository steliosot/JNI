class CatchThrow {
    private native void nativeThrow()
                       throws IllegalArgumentException;
    private static native void nativeThrowNew()
                       throws NullPointerException;

    public static void main(String args[]) {
        CatchThrow obj = new CatchThrow();
        try {
            System.out.println("In Java : Before call nativeThrow()");
            obj.nativeThrow();
            System.out.println("In Java : After  call nativeThrow()");
        } catch (Exception e) {
            System.out.println("In Java : " + e);
        }
        try {
            System.out.println("In Java : Before call nativeThrowNew()");
            nativeThrowNew();
            System.out.println("In Java : After  call nativeThrowNew()");
        } catch (Exception e) {
            System.out.println("In Java : " + e.getMessage());
        }
    }
    static {
        System.loadLibrary("CatchThrow");
    }
}

