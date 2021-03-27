import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class Main{

	static int mod=(int)1e9+7;
	
	static long fact[]=new long[(int)2e5+1];
	
	static void solve(Reader in, PrintWriter out){
		
		int n=in.nextInt(), m=in.nextInt(), k=in.nextInt();
		int p=in.nextInt();
		int a[]=in.readArray(p);
		
		
		long ans=nCr(m+n,k);
		
		for(int g: a) {
			int r=k-g;
			if(r>n || g>m) continue;
			ans-=nCr(n,r)*nCr(m,g)%mod;
			ans=ans%mod;
			ans=(ans+mod)%mod;
		}
		
		out.println(ans);
		
	}
	
	static long nCr(int n, int r) {
		return fact[n]*ppow(fact[n-r], mod-2) % mod *ppow(fact[r], mod-2) %mod;
	}
	
	static long ppow(long n, long m) {
		if(m==0) return 1;
		long tmp=ppow(n,m/2);
		tmp=tmp*tmp%mod;
		return m%2==0 ? tmp : tmp*n % mod;
	}
	
	public static void main(String[] args) throws IOException {
		PrintWriter out=new PrintWriter(System.out);
		Reader in=new Reader(System.in);	
		int ts=1;
		ts=in.nextInt();
		
		fact[0]=1;
		for(int i=1; i<fact.length; ++i) fact[i]=(long)i*fact[i-1]%mod;
		
		while(ts-->0) solve(in, out);
		out.close();
	}
	
	static void sort(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i: a) al.add(i);
		Collections.sort(al);
		for(int i=0; i<a.length; ++i) a[i]=al.get(i);
	}
	
	static class Reader{
		
		BufferedReader br;
		StringTokenizer to;
		
		Reader(InputStream stream){
			br=new BufferedReader(new InputStreamReader(stream));
			to=new StringTokenizer("");
		}
		String nextLine() {
			String line="";
			try {
				line=br.readLine();
			}catch(IOException e) {};
			return line;
		}
		String next() {
			while(!to.hasMoreTokens()) {
				try {
					to=new StringTokenizer(br.readLine());	
				}catch(IOException e) {}
			}
			return to.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int [] readArray(int n) {
			int a[]=new int[n];
			for(int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long [] readLongArray(int n) {
			long [] a =new long[n];
			for(int i=0; i<n; ++i) a[i]=nextLong();
			return a;
		}
	}	
	
}
