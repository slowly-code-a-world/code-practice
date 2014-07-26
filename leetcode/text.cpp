
Text Justification
Total Accepted: 6753 Total Submissions: 48306

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length. 

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int sum = 0;
        vector<string> record;
        vector<string> ret;
        string tmp;  int no_need = 0;
        
        if (1 == words.size() && 0 == words[0].compare("")) {
            for (int i = 0; i<L; i++) tmp+=" ";
            ret.push_back(tmp);
            return ret;
        }
        for (int i = 0; i<words.size(); i++) {
            if (0 == sum) {
                sum+=words[i].size();
                record.push_back(words[i]);
            } else {
                sum+=words[i].size() + 1;
                record.push_back(words[i]);
            }
            
            if (sum == L) {
                tmp.clear();
                for(int j =0; j<record.size(); j++) {
                    if (0 == j) tmp+=record[j];
                    else {
                        tmp+=" ";
                        tmp+=record[j];    
                    }    
                }
                ret.push_back(tmp);
                record.clear();
                sum = 0;
                if (i == words.size()-1)  no_need = 1;
            } else if (sum > L) {
                record.pop_back();
                tmp.clear();
                int real = 0;
                for (int i = 0; i<record.size(); i++) real+=record[i].size();
                int whites = L - real;
                int slots = record.size() - 1;
                if (0 == slots) {
                    tmp+=record[0];
                    for (int j = 0; j<whites; j++) tmp+=" ";
                } else {
                    int size = whites/slots;
                    int remain = whites % slots;
                    int cnt = 1;
                    for (int j = 0; j<record.size(); j++) {
                        if (0 == j) tmp+=record[j];
                        else {
                            for (int k=0; k<size; k++) tmp+=" ";
                            if (cnt<=remain) { tmp+=" "; cnt++; }
                            tmp+=record[j];
                        }
                    }
                }
                ret.push_back(tmp);
                record.clear();
                sum = words[i].size();
                record.push_back(words[i]);
            }
        }
        if (0 == no_need) {
            sum = 0;
            tmp.clear();
            for (int i = 0; i< record.size(); i++) {
                if (0 == i) { tmp+=record[i]; sum+= record[i].size(); }
                else {  tmp+=" "; tmp+=record[i]; sum+=record[i].size() + 1;}
            }
            for (int i = 0; i<L-sum; i++) tmp+=" ";
            ret.push_back(tmp);
        }    
        return ret;
    }
};
