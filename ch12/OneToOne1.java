public class OneToOne1 {
   public static native int atol(String str);
   public static void main(String[] args) {
   int x = atol("100");
   System.out.println(x);
   }
   static {
       System.loadLibrary("OneToOne1");
   }
}

