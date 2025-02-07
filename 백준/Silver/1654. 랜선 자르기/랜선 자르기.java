import java.util.*;

public class Main {

    static int k,n;
    static int[][] a = new int [5][5];
    static List<Integer> v = new ArrayList<>();

    static boolean go(Long x){
        Long cnt= 0L;
        for(int i=0;i<k;++i){
            cnt+=v.get(i)/x;
        }
        return cnt>=n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        k=sc.nextInt();
        n=sc.nextInt();
        for(int i=0;i<k;++i){
            v.add(sc.nextInt());
        }

        Long st=0L;
        Long en= (long) Math.pow(2,31)-1;
//        System.out.println(en);
        while(st<en){
            Long mid = (st+en+1)/2;

            if(go(mid)){
                st=mid;
            }
            else{
                en=mid-1;
            }
        }

        System.out.println(st);
    }
}