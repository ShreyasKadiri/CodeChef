/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
        Scanner sc = new Scanner(System.in);
		
		int n=0;
		n=sc.nextInt();
		
		List temp= new ArrayList<>();
		
		for(int i=0;i<=n;i++){
			String  s;
			s=sc.nextLine();
		    String [] array = s.split("\\s+");
		    String s1=" ";
		    for(int j=0;j<array.length;j++){
		    	if(array[j].equals("-1"))
		    		break;
		    	else
		    	s1+=array[j]+" ";
		    }
			temp.add(s1.trim());
		}
		Collections.sort(temp);
		
		for(int i=0;i<temp.size();i++){
			System.out.println(temp.get(i));
		}
	}
}
