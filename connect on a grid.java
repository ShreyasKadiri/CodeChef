/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
 class Codechef
{
	public static class box implements Comparable<box>{
        int X;
        int Y;
        int L;
        int R;
        int ind;
        public box(int x, int y, int l, int r,int i) {
            X = x;
            Y = y;
            L = l;
            R = r;
            ind=i;
        }
        public box(){}
        @Override
        public int compareTo(box o){
            if(this.Y<o.Y){
                return -1;
            }else if(this.Y>o.Y){
                return 1;
            }else{
                if(this.X<o.X){
                    return 1;
                }else if(this.X>o.X){
                    return -1;
                }else{
                    return 0;
                }
            }
       }
       
    }
    public static void calc(box[] arr, int K, int N, HashMap<Integer[],String> map){
        int i=1;
        int j=2;
        while(j<arr.length){
            int C=0;
            box b1=arr[i];
            box b2=arr[j];
            C+=Math.abs(b1.Y-b2.Y);
            C+=Math.abs(b1.X-b2.X);
            String path=devStr(b1,b2);
            C++;
            if(Math.max(b1.L,b2.L)<=C && Math.min(b1.R,b2.R)>=C){
                map.put(new Integer[]{b1.ind,b2.ind}, path);
            }
            i+=2;
            j+=2;
        }
    }
    public static String devStr(box b1, box b2){
        String ans="";
        char c1,c2;
        if(b1.Y>=b2.Y){
            c1='L';
        }else{
            c1='R';
        }
        if(b1.X>=b2.X){
            c2='U';
        }else{
            c2='D';
        }
        for(int i=0;i<Math.abs(b1.Y-b2.Y);i++){
            ans+=c1;
        }
        for(int i=0;i<Math.abs(b1.X-b2.X);i++){
            ans+=c2;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        int N = s.nextInt();
        int K = s.nextInt();
        box[] arr = new box[K+1];
        for(int i=0;i<K;i++){
            arr[i+1]=new box(s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt(),i+1);
        }
        Arrays.sort(arr, 1, K-1);
        HashMap<Integer[],String> map= new HashMap<>();
        calc(arr,K,N,map);   
        if(map.size()==0){
            return;
        }else{
            System.out.println(map.size());
        }
        for(Integer[] i:map.keySet()){
            System.out.println(i[0]+" "+i[1]+" "+map.get(i));
        }
    } 
	}
