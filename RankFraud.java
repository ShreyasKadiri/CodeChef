import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        FastReader s = new FastReader();
        int n = s.nextInt();
        int graph[][] = new int[n][n];
        
        for(int i=0; i<n; i++){
            int m=s.nextInt();
            for(int temp=0; temp<m; temp++){
                int j=s.nextInt()-1;
                graph[i][j] = 1;
            }
        }
        ArrayList ans = new ArrayList();
        ans.add(0);
        for(int i=1; i<n; i++){
            if(graph[i][(int)ans.get(0)] == 1) {
                ans.add(0,i);
            }
            else if(graph[(int)ans.get(ans.size()-1)][i]==1) {
                ans.add(i);
            }
            else{
                for(int j=0; j<ans.size()-1; j++){
                    if(graph[(int)ans.get(j)][i]==1 && graph[i][(int)ans.get(j+1)]==1){
                        ans.add(j+1,i);
                        break;
                    }
                }
            }
        }

        out.println("YES");
        for(int i=0;i<ans.size(); i++)
            out.print(((int)ans.get(i)+1) + " ");
        out.println();
        out.close();
    }


    public static PrintWriter out = new PrintWriter(System.out);
    public static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String next() {
            while (st==null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    }
}
