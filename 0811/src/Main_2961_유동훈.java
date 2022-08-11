import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2961_유동훈 {

	static int[] result;
	static int[] arr;
	static int r;
	static int[] answer;
	static boolean first=true;
	
	static void print()
	{
		for(int i=0;i<result.length;++i)
		{
			System.out.print(result[i]+" ");
		}
		System.out.println();
	}
	static void copy_arr()
	{
		for(int i=0; i<answer.length;++i)
		{
			answer[i]=result[i];
		}
	}
	
	/*
	 * r : nCr의 r, r만큼 result배열 생성해라.
	 * 
	 * 
	 */
	static void comb(int cnt, int start)
	{
		//result= new int[result.length][2];
		r=result.length;
		if(cnt==r) 
		{
			//print();
			int sum=0;
			for(int i=0; i<result.length;++i)
			{
				sum=sum+result[i];
			}
			if(sum==100) 
			{
				copy_arr();
				//first=false;
			}
			return;
		}
		
		for(int i=start;i<arr.length;++i)
		{
			result[cnt]=arr[i];
			comb(cnt+1,i+1);
		}

	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st;
		
		arr=new int[9];
		for(int i=0; i<arr.length;++i)
		{
			arr[i]=Integer.parseInt(br.readLine());
		}
		//입력 끝
		
		result=new int[7];
		answer=new int[7];
		comb(0,0);
		
		StringBuilder sb= new StringBuilder();
		for(int i=0; i<answer.length;++i)
		{
			sb.append(answer[i]+"\n");
		}
		System.out.println(sb);
	}

}
