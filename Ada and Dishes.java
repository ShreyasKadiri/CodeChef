/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		 int t = sc.nextInt();
		 while(t-- > 0){
		  int n = sc.nextInt();
            double sum=0;
            int a[] = new int[n];
            
            for(int i=0; i<n; i++){
                a[i]=sc.nextInt();
                sum+=a[i];
            }
            
            Arrays.sort(a);
            if(n==1)
            System.out.println(a[0]);
		    else if(n==2)
		    System.out.println(a[1]);
		    else{
		        int diff=findMin(a,n);
		        double half=sum/2;
		        double diffHalf=diff/2;
		        half=half-diffHalf;
		        half+=diff;
		        System.out.println((int)half);
		    }
		 }
	}
	
	public static int findMinRec(int a[], int i, int sumCalculated, int sumTotal){
	    if(i==0)
	    return Math.abs((sumTotal-sumCalculated)-sumCalculated);
	return Math.min(findMinRec(a,i-1,sumCalculated+a[i-1],sumTotal),
	findMinRec(a,i-1,sumCalculated,sumTotal));
}


public static int findMin(int a[], int n){
    int sumTotal=0;
    for(int i=0; i<n; i++){
        sumTotal+=a[i];
    }
    
    return findMinRec(a,n,0,sumTotal);
}
}
