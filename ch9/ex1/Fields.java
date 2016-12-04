class Fields {
    public int pubInt = 13;
    static public int statPubInt = 15;
    private int privInt = 17;
    private static float privStatFloat = 19.2f;
    public String strField = "ABC";

    private native void accessFields();
    private native void accessStrings();

    public static void main(String[] args) 
    {
       Fields obj = new Fields();
       obj.accessFields();
       obj.accessStrings();
       System.out.println("-----------------------------------");
       System.out.println("From C++  : pubInt = " + obj.pubInt);
       System.out.println("From C++  : statPubInt = " + obj.statPubInt);
       System.out.println("From C++  : privInt = " + obj.privInt);
       System.out.println("From C++  : privStatFloat = " + obj.privStatFloat);
       System.out.println("From C++  : strField = " + obj.strField);
    }
    static {
        System.loadLibrary("Fields");
    }
}

