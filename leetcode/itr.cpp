
Integer to Roman
Total Accepted: 11330 Total Submissions: 34253

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    void ITR(int num, string &ret) {
        if (num >= 1000) {
            int cnt = num/1000;
            for (int i = 0; i< cnt; i++) ret+="M";
            num -= cnt*1000;
            ITR(num, ret);
            return;
        }
        
        if (num>=100) {
            int cnt = num/100;
            if (cnt <=3) {
                for (int i = 0; i<cnt; i++) ret+="C";
                num -= cnt*100;
                ITR(num, ret);
                return;
            } 
            
            if (4 == cnt) {
                ret+="CD";
                num -= 400;
                ITR(num, ret);
                return;
            }
            
            if (5 == cnt) {
                ret+="D";
                num-=500;
                ITR(num, ret);
                return;
            }
            
            if (cnt >5 && cnt <=8) {
                ret+="D";
                for (int i = 0; i<cnt-5; i++) ret+="C";
                num-=cnt*100;
                ITR(num, ret);
                return;
            }
            
            if (9 == cnt) {
                ret+="CM";
                num-=900;
                ITR(num, ret);
                return;
            }
        }
        
        if (num>=10) {
            int cnt = num/10;
            if (cnt <=3) {
                for (int i = 0; i<cnt; i++) ret+="X";
                num-=cnt*10;
                ITR(num, ret);
                return;
            }
            if (4 == cnt) {
                ret+="XL";
                num-=40;
                ITR(num, ret);
                return;
            }
            if (5 == cnt) {
                ret+="L";
                num-=50;
                ITR(num, ret);
                return;
            }
            if (cnt > 5 && cnt <=8) {
                ret+= "L";
                for (int i = 0; i<cnt-5; i++) ret+="X";
                num -= cnt*10;
                ITR(num, ret);
                return;
            }
            if (9 == cnt) {
                ret+="XC";
                num-=90;
                ITR(num, ret);
                return;
            }
        }
        
        if (1 == num) ret+="I"; 
        if (2 == num) ret+="II";
        if (3 == num) ret+="III";
        if (4 == num) ret+="IV";
        if (5 == num) ret+="V";
        if (6 == num) ret+="VI";
        if (7 == num) ret+="VII";
        if (8 == num) ret+="VIII";
        if (9 == num) ret+="IX";
        return;
    } 
    string intToRoman(int num) {
        string ret;    
        ITR(num, ret);
        return ret;
    }
};
