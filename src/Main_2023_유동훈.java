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

public class Main_2023_유동훈 {

	static int N;
	static int m;

	static boolean check[];
	public static void isPrime(int m) 
	{
		check[0] = check[1] = true;
		for (int i = 2; i * i <= m; i++) {
			if (check[i] == true) {
				continue;
			}
			for (int j = i + i; j <= m; j += i) {
				check[j] = true;
			}
		}
	}

	
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(br.readLine());
		
		
		int start=0;
		int end=0;
		if(N==1)
		{
			start=1;
			end=9;
		}
		if(N==2)
		{
			start=11;
			end=99;
		}
		else if(N==3)
		{
			start=111;
			end=999;
		}else if(N==4)
		{
			start=1111;
			end=9999;
		}else if(N==5)
		{
			start=11111;
			end=99999;
		}else if(N==6)
		{
			start=111111;
			end=999999;
		}else if(N==7)
		{
			start=1111111;
			end=9999999;
		}else if(N==8)
		{
			start=11111111;
			end=99999999;
		}
		
		check = new boolean[end + 1];
		
		isPrime(end);
		
		LinkedList<Integer> stack = new LinkedList<Integer>();
		StringBuilder sb= new StringBuilder();
		for (int i = start; i <= end; i++) 
		{
			if (check[i] == false ) //소수면
			{
				int temp=i;
				while(temp > 0)
				{
					//temp = temp / 10;
		            stack.push(temp);
		            temp = temp / 10;
		        }
				boolean isdone=true;
		        while ((!stack.isEmpty()))
		        {
		            if(check[stack.pop()]==true)	//소수가아니면
		            {
		            	//stack.pop();
		            	isdone=false;
		            	stack.clear();
		            	break;
		            }
		        }
		        if(isdone)
		        	sb.append(i+"\n");
			}
		}
		
		System.out.println(sb);
		/*//sb.append("sdff");
		//System.out.println(sb);
		LinkedList<Integer> stack = new LinkedList<Integer>();
		int a=7331;
		while(a > 0)
		{
			//temp = temp / 10;
            stack.push(a);
            a = a / 10;
        }
		boolean isdone=true;
        while ((!stack.isEmpty()))
        {
            System.out.println(stack.pop());
        }
*/

	}

}
