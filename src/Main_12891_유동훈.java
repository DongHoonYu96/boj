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

public class Main_12891_유동훈 {

	static int S;
	static int P;
	static Queue<Integer> q=new LinkedList<>();
	static StringBuilder sb= new StringBuilder();
	static int[] dna=new int[4];
	static int count;
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
		StringBuilder temp= new StringBuilder();
		temp.append(sb.substring(0, P));
		for(int i=0;i<=S-P;++i)
		{
			
			int[] temp2=new int[4];
			for(int q=0;q<4;++q)
			{
				temp2[q]=dna[q];
			}
			for(int j=0;j<temp.length();++j)
			{
				if(temp.charAt(j)!='A' && temp.charAt(j)!='C' && temp.charAt(j)!='G' && temp.charAt(j)!='T')
					break;
				if(temp.charAt(j)=='A' )
					temp2[0]--;
				else if(temp.charAt(j)=='C' )
					temp2[1]--;
				else if(temp.charAt(j)=='G' )
					temp2[2]--;
				else if(temp.charAt(j)=='T' )
					temp2[3]--;
			}
			
			boolean isdone=true;
			for(int k=0;k<4;++k)
			{
				if(temp2[k]>0)
				{
					isdone=false;
					break;
				}
			}
			if(isdone) count++;
			
			if(P+i<sb.length())
			{
				temp.deleteCharAt(0);
				//int p=0;
				//if(i==0)p=P;
				temp.append(sb.charAt(P+i));
			}
			
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		S=Integer.parseInt(st.nextToken());
		P=Integer.parseInt(st.nextToken());
		//st = new StringTokenizer(br.readLine()," ");
		sb.append(br.readLine());
		
		st = new StringTokenizer(br.readLine()," ");
		for(int i=0;i<4;++i)
		{
			dna[i]=Integer.parseInt(st.nextToken());
		}
		
		sol();
		System.out.println(count);


	}

}
