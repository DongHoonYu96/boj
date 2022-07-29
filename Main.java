package boj;

import java.util.Scanner;

public class Main {
	public static int sol(int input)
	{
		int count=0;
		int temp=-1;

		int a,b;
		if(input<10)
		{
			a=0;
			b=input;
		}
		else
		{
			a=input/10;
			b=input%10;
		}
		while(true)
		{
			if(input==temp) break;
			
			temp=a+b;
			temp=temp%10;
			temp=10*b+temp;
			
			a=temp/10;
			b=temp%10;
			count++;
		}
		
		
		
		
		
		
		
		return count;
	}
	
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int input=sc.nextInt();
		//int temp=-1;
		int answer=sol(input);
		System.out.println(answer);

	}

}
