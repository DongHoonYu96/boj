import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_11659_유동훈 {

	//static int[][] memo;
	//static List<List<Integer>> list= new ArrayList<>();
	
	static Map<String,Integer> hMap=new HashMap<>();
	static int data[];
	static int sum[];
	static int sol(int x, int y)
	{
		return 0;
	}
	static int sum(int i, int j)
	{
		//hMap.putIfAbsent("11", 0);
		//if(i==j) return data[i];
		//return sum(i,j-1)+sum(i+1,j);
		
		if(i==j)
		{
			return data[i];
		}
		
		String key=Integer.toString(i)+Integer.toString(j);
		if(hMap.get(key)==null)	//메모가없으면
		{
			hMap.put(key, sum(i,j-1)+sum(j,j));
		}
		return hMap.get(key);
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		//Scanner sc = new Scanner(System.in);
		//st = new StringTokenizer(br.readLine()," ");
		int N=Integer.parseInt(st.nextToken());
		//st = new StringTokenizer(br.readLine()," ");
		int M=Integer.parseInt(st.nextToken());
		//T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/
		st = new StringTokenizer(br.readLine()," ");
		data= new int[N];	
		sum=new int[N+1];
		
		//sum[1]=data[0];
		for(int i=1;i<=N;++i)	//O(10만)
		{
			sum[i]=sum[i-1]+Integer.parseInt(st.nextToken());;
		}
		
		//메모하기 추가!!!
		//memo=new int[N][N];
		
		for(int test_case = 1; test_case <= M; test_case++)	//O(10만)
		{
			//String s=br.readLine();
			
			st = new StringTokenizer(br.readLine()," ");
			int a=Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			//입력끝
			//System.out.println(Arrays.toString(sum));
			System.out.println(sum[b]-sum[a-1]);
		}

	}

}
