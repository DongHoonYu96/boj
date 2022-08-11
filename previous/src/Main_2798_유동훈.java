import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_2798_유동훈 {

	//static int[][] memo;
	//static List<List<Integer>> list= new ArrayList<>();
	static int[] data;
	static int N;
	static int M;
	//static List<Integer> list= new ArrayList<>();
	static void print()
	{
		//for(int i=0;i<N;++i)
			System.out.println(Arrays.toString(data));
	}
	static int sol()
	{
		//List<Integer> list= new ArrayList<>();
		int max=0;
		int a=0,b=0,c = 0;
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j)
				for(int k=j+1;k<N;++k)
				{
					int temp=data[i]+data[j]+data[k];
					if(temp<=M && temp>max)
					{
						max=temp;
						a=i;b=j;c=k;
					}
						
				}
		//System.out.println("인덱스 : "+a+b+c);
		return max;
		//Collections.reverse(list);
		//return list.get(0);
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		//Scanner sc = new Scanner(System.in);
		//st = new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		data=new int[N];
		
		st = new StringTokenizer(br.readLine()," ");
		for(int i=0;i<N;++i)
		{
			data[i]=Integer.parseInt(st.nextToken());
		}
		//print();
		//입력 끝
		
		
		System.out.println(sol());
		
		//print();
		StringBuilder sb= new StringBuilder();
		/*for(int test_case = 1; test_case <= M; test_case++)	//O(10만)
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
		System.out.println(sb);*/

	}

}
