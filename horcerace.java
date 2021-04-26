import java.util.*;
import java.io.*;
import java.math.*;
class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        List<Integer> p = new ArrayList<>();
        List<Integer> ppp = new ArrayList<>();
        int max = 10000000;
        int temp;
        for (int i = 0; i < N; i++) {
            int pi = in.nextInt();
            p.add(pi);
        }
        p.sort(null);
        int i=0;
        int j=1;
        if((p.get(0)<p.get(p.size()-1))&& p.get(p.size()-1)!=0){
            if(p.get(p.size()-1)!=p.get(p.size()-2)){
                while(true){
                    i++;j++;
                    if((p.get(p.size()-i)-p.get(p.size()-j))!=0){
                        System.err.println(Math.abs(p.get(p.size()-j)-p.get(p.size()-i)));
                        ppp.add(Math.abs(p.get(p.size()-j)-p.get(p.size()-i)));
                    }
                    if((p.get(p.size()-j)==p.get(0))){
                        break;
                    }
                }
            }
        }
        ppp.sort(null);
        if(ppp.get(0)>ppp.get(ppp.size()-1)){
            System.out.println(ppp.get(ppp.size()-1));
        }
        else if (ppp.get(0)<ppp.get(ppp.size()-1)){
            System.out.println(ppp.get(0));
        }else if(ppp.size()==1){
            System.out.println(ppp.get(0));
        }
    }
}
