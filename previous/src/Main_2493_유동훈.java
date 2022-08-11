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

public class Main_2493_유동훈 {

	static int N;
	//static int m;
	static int[] data;
	static int[] ans;

	static boolean check[];
	public static int laser(int me)
	{
		for(int i=me;i>=0;--i)
		{
			if(data[i]>data[me]) return i+1;
		}
		return 0;
	}

	
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		data=new int[N];
		ans=new int[N];
		for(int i=0;i<N;++i)
		{
			data[i]=Integer.parseInt(st.nextToken());
		}
		//입력 끝
		
		for(int i=N-1;i>=0;--i)
		{
			ans[i]=laser(i);
		}
		
		System.out.println(Arrays.toString(ans));
		
		
		
	}

}
