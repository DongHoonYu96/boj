import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_11866_유동훈 {

	static int N;
	static int K;
	static Queue<Integer> q=new LinkedList<>();
	static StringBuilder sb= new StringBuilder();
	static void print()
	{
		while(!q.isEmpty())
		{
			System.out.print(q.poll()+" ");
		}
		System.out.println();
	}
	static void sol()
	{
		for(int i=1;i<=N;++i)
		{
			q.add(i);
		}
		//입력
		
		while(!q.isEmpty())
		{
			for(int i=0;i<K-1;++i)
			{
				int temp=q.poll();
				q.add(temp);
			}
			sb.append(q.poll()+", ");
		}
		
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());

		
		sb.append("<");
		sol();
		sb.deleteCharAt(sb.length()-1);
		sb.deleteCharAt(sb.length()-1);
		sb.append(">");
		System.out.println(sb);


	}

}
