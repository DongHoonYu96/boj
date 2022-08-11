import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_1011_유동훈 {

	
	static int sol(int x, int y)
	{
		if(y-x==1) return 1;
		if(y-x==2) return 2;
		if(y-x==3) return 3;
		
		int[] possible= {0,1,2};
		int pos=0;
		int stripe=1;
		int answer=2;
		int[] data=new int[y-x-1];
		//데이터생성
		for(int i=0;i<data.length;++i)
		{
			data[i]=i;
		}
		
		//보폭큰거부터 가능한지 검사
		for(;pos<data.length;)
		{
			//if(data[pos]==data.length-1) break;
			
			if(pos+possible[2]<data.length)
			{
				pos=pos+possible[2];
				stripe=possible[2];
			}
			else if(pos+possible[1]<data.length)
			{
				pos=pos+possible[1];
				stripe=possible[1];
			}
			else if(pos+possible[0]<data.length)
			{
				pos=pos+possible[0];
				stripe=possible[0];
			}
			possible[0]=stripe-1;
			possible[1]=stripe;
			possible[2]=stripe+1;
			
			answer++;
		}
		/*while(true)
		{
			if(data[pos]==data.length-1) break;
			
			if(pos+possible[2]<data.length)
			{
				pos=pos+possible[2];
				stripe=possible[2];
			}
			else if(pos+possible[1]<data.length)
			{
				pos=pos+possible[1];
				stripe=possible[1];
			}
			else if(pos+possible[0]<data.length)
			{
				pos=pos+possible[0];
				stripe=possible[0];
			}
			possible[0]=stripe-1;
			possible[1]=stripe;
			possible[2]=stripe+1;
			
			answer++;
		}*/
	
		return answer;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		//Scanner sc = new Scanner(System.in);
		int T;
		T=Integer.parseInt(br.readLine());
		//T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int x=Integer.parseInt(st.nextToken());
			int y=Integer.parseInt(st.nextToken());

			int answer=sol(x,y);
			System.out.println(answer);
		}

	}

}
