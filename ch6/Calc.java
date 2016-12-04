class Calc
{
    private native int sum(int num1, int num2);
    private static native double div(double num1, double num2);

    public static void main(String[] args) 
    {
       Calc obj = new Calc();
       int iNum1 = 13;
       int iNum2 = 15;
       int iRes =obj.sum(iNum1, iNum2);
       System.out.println(iRes);
       double dNum1 = 21.2;
       double dNum2 = 4.5;
       double dRes = div(dNum1, dNum2);
       System.out.println(dRes);
    }
    static {
        System.loadLibrary("Calc");
    }
}

