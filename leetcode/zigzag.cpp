
ZigZag Conversion
Total Accepted: 10023 Total Submissions: 42566

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

class Solution {
public:
    string convert(string s, int nRows) {
        string ret;
        if (nRows < 1) return ret;
        if (nRows == 1) return s;
        vector<vector<char> > map;
        for (int i = 0; i<nRows; i++) {
            vector<char> row;
            map.push_back(row);
        }
        int control = 0; int down = 1;
        for (int i = 0; i<s.size(); i++) {
            map[control].push_back(s[i]);
            if (1 == down) {
                if (control < nRows-1) 
                    control++;
                else {
                    control--;
                    down = 0;
                }    
            } else {
                if (control > 0)
                    control --;
                else {
                    control ++;
                    down = 1;
                }    
            }
        }
        for (int i = 0; i<nRows; i++) {
            for (int j = 0; j<map[i].size(); j++) {
                ret+=map[i][j];
            }
        }
        return ret;    
    }
};
