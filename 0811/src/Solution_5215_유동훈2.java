import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution_5215_유동훈2 {

	static int N;
	static int L;
	//static int answer;
	//static Stack<int[]> stack;
	//static int[][] arr;
	//static int[][] result;
	//static boolean[] visit;
	//static int r;
	
	
	public static int knapsack(int[] v, int[] w, int n, int W)
    {
        // 기본 경우: 음수 용량
        if (W < 0) {
            return Integer.MIN_VALUE;
        }
 
        // 기본 경우: 남은 항목이 없거나 용량이 0이 됨
        if (n < 0 || W == 0) {
            return 0;
        }
 
        // 사례 1. 배낭에 현재 항목 `v[n]`을 포함하고
        // 용량이 감소된 나머지 항목 `n-1` `W-w[n]`
 
        int include = v[n] + knapsack(v, w, n - 1, W - w[n]);
 
        // 사례 2. 배낭에서 현재 항목 `v[n]`을 제외하고
        // 나머지 항목 `n-1`
 
        int exclude = knapsack(v, w, n - 1, W);
 
        // 현재 항목을 포함하거나 제외하여 얻은 최대 값을 반환합니다.
        return Integer.max(include, exclude);
    }
	
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());
		StringTokenizer st ;
		for(int tc = 1;tc<=TC;tc++) 
		{
		
			st = new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			L=Integer.parseInt(st.nextToken());
			
			//arr = new int[N][2];
			
			
			int[] v=new int[N];	//가격
			int[] w=new int[N];	//무게
			int W=L;	//최대무게(배낭용량)
			
			for(int i=0;i<N;++i)
			{
				st = new StringTokenizer(br.readLine());	
				v[i]=Integer.parseInt(st.nextToken());
				w[i]=Integer.parseInt(st.nextToken());

			}
			//입력끝

			System.out.println("#"+tc+" "+knapsack(v, w, v.length - 1, W));
			
			
			
			
			
			
			
		}

	}


}
