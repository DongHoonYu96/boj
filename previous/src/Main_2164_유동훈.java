import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_2164_유동훈 {

	static Queue<Integer> q= new LinkedList<>();
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int num=sc.nextInt();
		
		for(int i=1;i<=num;++i)
		{
			q.add(i);
		}
		
		int answer=0;
		while(!q.isEmpty())
		{
			answer=q.poll();
			if(q.isEmpty())
			{
				break;
			}
			else
			{
				int temp=q.poll();
				q.add(temp);
			}
		}
		System.out.println(answer);
	}

}
