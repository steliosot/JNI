class Methods {
    private native void accessConstructor();
    private native void accessStaticMethod();
    private native void accessInstanceMethod();



    private String recSendString(String s) {
       System.out.println("In Java : "+ s);
       return new String("Hello from Java");
    }
    private static int intSumStatic(int num1, int num2) {
       return num1 + num2;
    }
    Methods() {
      System.out.println("Constructor ! ");
    }
    Methods(String s) {
      System.out.println("Constructor called from : " + s);
    }

    public static void main(String[] args) 
    {
       Methods c = new Methods("Java");
       c.accessConstructor();  
       c.accessStaticMethod();
       c.accessInstanceMethod();
    }
    static {
        System.loadLibrary("Methods");
    }
}

