//**********************************************
// Arrays of Objects (Small fixed-size arrays)
//**********************************************
class Arrays11 {
    int arraySize=-1;
    private int arrayResults[][];

    public native int[][]
                   mulInt2DArray(int[][] a, int[][] b);
    public native void
                   mulScalarInt2DArray(int[][] a, int[] b);

    public void sendInt2DArray(int[][] results) {
       arraySize = results.length;
       arrayResults = new int[ results.length ][];
       System.arraycopy(results, 0, arrayResults, 0, arraySize);
    }
    public void displayArray() {
       System.out.println("*********************************");
       for (int i = 0; i < arraySize; i++) {
          for (int j = 0; j < arrayResults[i].length; j++) {
             System.out.print(arrayResults[i][j] + "    ");
          }
          System.out.println();
       }
    }
    public void displayArray1(int[][] arr) {
       System.out.println("*********************************");
       for (int i = 0; i < arr.length; i++) {
          for (int j = 0; j < arr[i].length; j++) {
             System.out.print(arr[i][j] + "    ");
          }
          System.out.println();
       }
    }
    public static void main(String[] args)
    {
       int lines = 3;
       int columns = 3;
       int[][] ar1 = new int[3][3];
       int[][] ar2 = new int[3][3];
       int[][] ar3 = new int[3][3];
       int[]   ar4 = new int[columns];

       int num1=1, num2=1;

       for (int i = 0; i < lines; i++) {
          ar4[i] = 5;
          for (int j = 0; j < columns; j++) {
             ar1[i][j] = num1;
             ar2[i][j] = num2;
          }
          num1++;
          num2++;
       }
       Arrays11 a = new Arrays11();
       int[][] int2DArray2 = a.mulInt2DArray(ar1,ar2);
       a.mulScalarInt2DArray(ar1,ar4);
       a.displayArray1(int2DArray2);
       a.displayArray();
    }
    static {
        System.loadLibrary("Arrays11");
    }
}

