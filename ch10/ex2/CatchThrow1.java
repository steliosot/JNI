class CatchThrow1 {
    private native void catchException(int intArg) throws Exception;

    private void callbackThrow() throws Exception {
        System.out.println("In Java : callback() THROWS NULLPOINTEREXCEPTION");
        throw new NullPointerException("From Java callbackException");
    }

    private void callbackThrow(int intArg) throws Exception {
        if (intArg == 1) {
            System.out.println("In Java : THROWS NULL POINTER EXCEPTION");
            throw new NullPointerException("From Java callbackException");
        }
        else if (intArg == 2) {
            System.out.println("In Java : THROWS INSTATIATION EXCEPTION");
            throw new InstantiationException("From Java callbackException");
        }
        else {
            System.out.println("In Java : THROWS ILLEGAL ARGUMENT EXCEPTION");
            throw new IllegalArgumentException("From Java callbackException");
        }
    }

    public static void main(String args[]) {
        try {
               CatchThrow1 obj = new CatchThrow1();
               System.out.println("In Java : Before call callbackThrow()");
               obj.catchException(1);
               System.out.println("In Java : After  call callbackThrow()");
        } catch (Exception e) {
               System.out.println("In Java : " + e);
        }
        System.out.println("---------------------------");
        try {
               CatchThrow1 obj = new CatchThrow1();
               System.out.println("In Java : Before call callbackThrow()");
               obj.catchException(2);
               System.out.println("In Java : After  call callbackThrow()");
        } catch (Exception e) {
               System.out.println("In Java : " + e);
        }
    }
    static {
        System.loadLibrary("CatchThrow1");
    }
}

