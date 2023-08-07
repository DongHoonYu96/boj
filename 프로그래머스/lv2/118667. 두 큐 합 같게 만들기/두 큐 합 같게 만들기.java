import java.util.*;

class Solution {
    static Queue<Integer> q1=new LinkedList<>();
    static Queue<Integer> q2=new LinkedList<>();
    static int answer;
    static long sum1;
    static long sum2;
    static long total;
    
    public int solution(int[] queue1, int[] queue2) {
        
        for(int i : queue1){
            q1.add(i);
            sum1+=i;
            total+=i;
        }
        for(int i : queue2){
            q2.add(i);
            sum2+=i;
            total+=i;
        }
        
        //System.out.println("목표: "+total/2);
        //System.out.println(sum1);
        //System.out.println(sum2);
        // for(int item : queue1){
        //     System.out.println(item);
        // }
        // for(int item : queue2){
        //     System.out.println(item);
        // }
        //##############입력테스트 완료##################
        
        while(true){
            if(sum1==total/2 && sum2==total/2 && sum1==sum2){
                break;
            }
            if(answer>=4*queue1.length) return -1;
            
            //System.out.println("sum1: "+sum1);
            //System.out.println("sum2: "+sum2);
            if(sum1>sum2){
                int temp=q1.poll();
                q2.offer(temp);
                sum1-=temp;
                sum2+=temp;
                //System.out.println("temp: "+temp);
            }
            else if(sum1<sum2){
                int temp=q2.poll();
                q1.offer(temp);
                sum1+=temp;
                sum2-=temp;
                //System.out.println("temp: "+temp);
            }
            
            //#########sum 갱신###################
            // sum1=0;
            // sum2=0;
            // for(int i : q1){
            //     //q1.add(i);
            //     sum1+=i;
            //     //total+=i;
            // }
            // for(int i : q2){
            //     //q2.add(i);
            //     sum2+=i;
            //     //total+=i;
            // } 시간초과 -> sum갱신시 반복문 필요없음.
            
            
            answer++;
        }
        
        
        return answer;
    }
}