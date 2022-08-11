import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution_5215_유동훈 {

	static int N;
	static int L;
	static int answer;
	//static Stack<int[]> stack;
	static int[][] arr;
	static int[][] result;
	//static boolean[] visit;
	static int r;
	static void print()
	{
		for(int i=0;i<result.length;++i)
		{
			for(int j=0;j<2;++j)
			{
				System.out.print(result[i][j]+" ");
			}
			System.out.println();
		}
	}
	static void calc()
	{
		
		int sum_score=0;
		int sum_kcal=0;
		for(int i=0;i<result.length;++i)
		{

			sum_score+=result[i][0];
			sum_kcal+=result[i][1];
			
			 //return;
			
		}
		if(sum_kcal<=L) answer=Math.max(answer, sum_score);
		System.out.println("점수:"+sum_score+" 칼로리:"+sum_kcal+" 답:"+answer);
	}
	static void comb(int cnt, int start)
	{
		//result= new int[result.length][2];
		r=result.length;
		if(cnt==r) 
		{
			System.out.println("길이:" +result.length);
			print();
			System.out.println();
			calc();
			return;
		}
		
		for(int i=start;i<N;++i)
		{
			result[cnt]=arr[i];
			comb(cnt+1,i+1);
		}

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
			
			arr = new int[N][2];
			
			
			
			for(int i=0;i<N;++i)
			{
				st = new StringTokenizer(br.readLine());				
				int[] temp=new int[2];
				temp[0]=Integer.parseInt(st.nextToken());
				temp[1]=Integer.parseInt(st.nextToken());
				arr[i]=temp;
			}
			//입력끝
			
			
			
			//nCr에서 n은 N, r은 result의 크기
			//r=N~1까지		
			for(int i=N;i>=0;--i)
			{
				r=i;
				result = new int[r][2];	
				comb(0,0);
			}
			/*r=5;
			result = new int[r][2];	
			comb(0,0);*/
			System.out.println("#"+tc+" "+answer);
			
			
			
			
			
			
			
		}

	}


}
