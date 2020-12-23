/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		   try 
		   {
		     BufferedReader read=new BufferedReader(new InputStreamReader(System.in));
		         int test=Integer.parseInt(read.readLine());
		         while(test-->0)
		         {
		             int n=Integer.parseInt(read.readLine());
		               boolean isP=prime(n);
		               if(!isP)
		               {
		                   System.out.println("No");
		               }
		               else{
		                boolean isPaline=paline(n);
		                if(isPaline)
		                {
		                    System.out.println("Yes");
		                }
		                else{
		                    System.out.println("No");
		                }
		                
		               }
		         }
		       
		   }
		   catch(Exception e)
		   {
		       
		   }
	}
	private static boolean paline(int n)
	{
	        int temp=n;
	        int sum=0;
	        while(temp>0)
	        {  
	          int rem=temp%10;
	          temp=temp/10;
	          sum=(sum*10)+rem;
	            
	        }
	        if(sum==n)
	        {
	            return true;
	        }
	        return false;
	}
	private static boolean prime(int n)
	{
	         for(int i=2;i<=n/2;i++)
	         {
	             if(n%i==0)
	             {
	                 return false;
	             }
	         }
	         return true;
	    
	}
}
