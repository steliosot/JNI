class Arrays {
    private native int[] createIntArray(int size);
    private native int sumSmallArray(int[] arrpar);
    private native int sumLargeArray(int[] arrpar);

    private native void updateArray(int[] arrpar);
    public static void main(String[] args) 
    {
       Arrays a = new Arrays();
       int arr[] = a.createIntArray(10);
       for (int i = 0; i < 10; i++) {
           arr[i] = i;
       }
       int sum = a.sumSmallArray(arr);
       System.out.println("Sum = " + sum);
       int sum1 = a.sumLargeArray(arr);
       System.out.println("Sum1 = " + sum1);
       
       //************************************
       a.updateArray(arr);
       for (int i = 0; i < 10; i++) {
           System.out.println(arr[i]);
       }
    }
    static {
        System.loadLibrary("Arrays");
    }
}

