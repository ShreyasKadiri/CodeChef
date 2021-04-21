import java.io.*;
import java.util.*;
import java.lang.*;
import static java.lang.System.out;

class Solution
{
    public static int maxSubArraySum(int[] arr)
	{
		int maxSoFar=arr[0], maxSub=arr[0];
		int len = arr.length;
		for (int i=1; i<len; i++)
		{
			maxSub = Math.max( (maxSub + arr[i]) , arr[i] );
			maxSoFar = Math.max( maxSoFar , maxSub );
		}
		return Math.max(0,maxSoFar);
	}
	public static void main (String [] $__$) throws java.lang.Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter o_o = new PrintWriter(System.out);	// (O_x)
		StringBuilder sss = new StringBuilder("");
		Scanner scan = new Scanner(System.in);
		
		int N = Integer.parseInt(in.readLine().trim());
		String[] input = in.readLine().trim().split("\\s+");
		int A = Integer.parseInt(input[0]);
		int B = Integer.parseInt(input[1]);
		int C = Integer.parseInt(input[2]);
		String S = in.readLine().trim();
		char[] CC = S.toCharArray();
		int[] R = new int[N];
		
		int mod0=0, mod1=0, mod2=0;
		for (int i=0; i<N; i++)
		{
		    int curr = ((int)(CC[i]));
		    R[i] = curr%3;
		    if ( curr % 3 == 0 )
		        ++mod0;
		    else if ( curr % 3 == 1 )
		        ++mod1;
		    else if ( curr % 3 == 2 )
		        ++mod2;
		}
		List<Pair> MOD = new ArrayList<Pair>(3);
		MOD.add( new Pair( 0,mod0 ) );
		MOD.add( new Pair( 1,mod1 ) );
		MOD.add( new Pair( 2,mod2 ) );
		Collections.sort(MOD);
		
		int max1 = Math.max( A,Math.max(B,C) );
		int max3 = Math.min( A,Math.min(B,C) );
		int max2 = A+B+C - (max1+max3);
		Map<Integer,Integer> map = new HashMap<>();
		map.put(MOD.get(0).mod , max1);
		map.put(MOD.get(1).mod , max2);
		map.put(MOD.get(2).mod , max3);
		
		int[] XYZ = new int[N];
		for (int i=0; i<N; i++)
		{
		    int curr = ((int)(CC[i])) % 3;
		    XYZ[i] = map.get( curr );
		}
		int result = maxSubArraySum( XYZ );
		for (int i=0; i<N; i++)
		{
		    int curr = ((int)(CC[i])+1) % 3;
		    XYZ[i] = map.get( curr );
		}
        result = Math.max( maxSubArraySum( XYZ ),result );
        for (int i=0; i<N; i++)
		{
		    int curr = ((int)(CC[i])+2) % 3;
		    XYZ[i] = map.get( curr );
		}
        result = Math.max( maxSubArraySum( XYZ ),result );
        /*out.println( Arrays.toString(CC) );
        out.println( Arrays.toString(R) );
        out.println( "M0="+mod0+" M1="+mod1+" M2="+mod2 );
        out.println( MOD.toString() );
        out.println( map );
        out.println( Arrays.toString(XYZ) );*/
		out.print( result );
		in.close();	o_o.close();
	}   // ƒ(Main)
}
class Pair implements Comparable<Pair>
{
    int mod, freq;
    Pair (int a, int b)
    {
        mod = a;
        freq = b;
    }
    public int compareTo(Pair p)
    {
        return p.freq-this.freq;
    }
    public String toString()
    {
    	return ("(" + mod + " , " + freq + ")");
    }
}
