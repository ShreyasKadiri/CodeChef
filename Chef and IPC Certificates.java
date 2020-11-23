import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.Scanner;

// Remember that the class name should be "Main" and should be "public".
public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int  N = sc.nextInt();
	int M = sc.nextInt();
	int  K = sc.nextInt();
	 
	 int c=0;
	 for(int i=0;i<N;i++)
	 {
	      int s=0;
	      for(int j=0;j<K;j++){
	          int x = sc.nextInt();
	          s = s + x;
	      }
	      int q =sc.nextInt();
	      
	      if(q <= 10 && (s>=M))
	        c++;
	 }
	 System.out.println(c);
	}
}
