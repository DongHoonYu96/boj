import java.util.*;


class Solution {
    static HashMap<Character, Integer> m=new HashMap<>();
    static String answer;
    
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        //그냥 돌면서 맵에 답아 m['R']=점수
        int i=0;
        for(String s: survey){
            System.out.println(s);
            
            if(choices[i]==1){
                char ch=s.charAt(0);
           		m.put(ch,m.getOrDefault(ch,0)+3);
            }
            else if(choices[i]==2){
                char ch=s.charAt(0);
           		m.put(ch,m.getOrDefault(ch,0)+2);
            }
            else if(choices[i]==3){
                char ch=s.charAt(0);
           		m.put(ch,m.getOrDefault(ch,0)+1);
            }
            else if(choices[i]==4){
                //pass
            }
            else if(choices[i]==5){
                char ch=s.charAt(1);
           		m.put(ch,m.getOrDefault(ch,0)+1);
            }
            else if(choices[i]==6){
                char ch=s.charAt(1);
           		m.put(ch,m.getOrDefault(ch,0)+2);
            }
            else if(choices[i]==7){
                char ch=s.charAt(1);
           		m.put(ch,m.getOrDefault(ch,0)+3);
            }
            ++i;
        }
        
        //맵 출력방법
        m.forEach((key, value) -> {
            System.out.println(key + " : " + value);
        });
        
    	String s1="RTCFJMAN";
    	for(int j=0; j<s1.length();j=j+2){
    		//System.out.println(s1.charAt(j));
            char c1=s1.charAt(j);
            char c2=s1.charAt(j+1);
            
            if(m.getOrDefault(c1,0)>=m.getOrDefault(c2,0)){
                answer+=c1;
            }
            else answer+=c2;
    	}

        return answer;
    }
}