import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	//static int[][] memo;
	//static List<List<Integer>> list= new ArrayList<>();
	static int[][] data;
	static int N;
	static void print()
	{
		for(int i=0;i<N;++i)
			System.out.println(Arrays.toString(data[i]));
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		//Scanner sc = new Scanner(System.in);
		//st = new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(st.nextToken());
		//st = new StringTokenizer(br.readLine()," ");
		int M=Integer.parseInt(st.nextToken());
		//T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/
		
		data= new int[N+1][N+1];	
		for(int i=1;i<=N;++i)	//O(10만)
		{
			st = new StringTokenizer(br.readLine()," ");
			for(int j=1;j<=N;++j)
			{
				data[i][j]=data[i][j-1]+Integer.parseInt(st.nextToken());
			}
			
		}
		
		//print();
		StringBuilder sb= new StringBuilder();
		for(int test_case = 1; test_case <= M; test_case++)	//O(10만)
		{
			//String s=br.readLine();
			int answer=0;
			st = new StringTokenizer(br.readLine()," ");
			int x1=Integer.parseInt(st.nextToken());
			int y1=Integer.parseInt(st.nextToken());
			int x2=Integer.parseInt(st.nextToken());
			int y2=Integer.parseInt(st.nextToken());
			//입력끝
			
			//print();
			for(int i=x1;i<=x2;++i)
			{
				answer=answer+data[i][y2]-data[i][y1-1];
			}
			//System.out.println(data[x1][y2]-data[x1][y1] + data[x2][y2]-data[x2][y1]);
			//System.out.println(answer);
			sb.append(answer+"\n");
		}
		System.out.println(sb);

	}

}
