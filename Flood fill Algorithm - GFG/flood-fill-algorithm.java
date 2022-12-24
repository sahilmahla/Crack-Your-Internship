//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] image =  new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S2 = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++)
                    image[i][j] = Integer.parseInt(S2[j]);
            }
            String[] S3 = br.readLine().trim().split(" ");
            int sr = Integer.parseInt(S3[0]);
            int sc = Integer.parseInt(S3[1]);
            int newColor = Integer.parseInt(S3[2]);
            Solution obj = new Solution();
            int[][] ans = obj.floodFill(image, sr, sc, newColor);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends


class Solution
{
    public  void dfs(int[][] res,int sr,int sc,int iniColor,int newColor,int[] row,int[] col){
        res[sr][sc] = newColor;
        int n = res.length;
        int m = res[0].length;
        for (int i = 0; i < 4; i++) {
            int nhRow = sr+row[i];
            int nhCol = sc+col[i];
            if(nhRow >=0 && nhRow < n && nhCol>=0 && nhCol < m && res[nhRow][nhCol] != newColor && res[nhRow][nhCol] == iniColor)
                dfs(res,nhRow,nhCol,iniColor,newColor,row,col);
        }

    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor)
    {
        int iniColor = image[sr][sc];

        int[] row = {-1,0,1,0};
        int[] col = {0,1,0,-1};
        dfs(image,sr,sc,iniColor,newColor,row,col);

        return image;
    }
}