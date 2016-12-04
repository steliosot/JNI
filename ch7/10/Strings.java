class Strings {
    private native String getSendMsg(String str);
    public static void main(String[] args) 
    {
       Strings obj = new Strings();
       String strOut = "Hello from Java";
       String strIn;
       strIn = obj.getSendMsg(strOut);
       System.out.println("In Java : " + strIn);
    }
    static {
        System.loadLibrary("Strings");
    }
}

