
Simplify Path
Total Accepted: 9182 Total Submissions: 46687

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ret;
        if (0 == path.size()) return "";
        if (1 == path.size()) return "/";
        string tmp;
        for (int i = 0; i < path.size(); i++) {
            if ('/' == path[i]) {
                if (0!=tmp.size()) {
                    int start, end, i = 0;
                    while (i < tmp.size() && ' ' == tmp[i]) i++;
                    if (i == tmp.size()) continue;
                    start = i;
                    while (i < tmp.size() && ' '!=tmp[i]) i++;
                    end = i; end --;
                    if (0 == tmp.substr(start, end - start + 1).compare(".")) {
                        tmp.clear();
                    } else if (0 == tmp.substr(start, end - start + 1).compare("..")) {
                        if (0 != ret.size())
                            ret.pop_back();
                        tmp.clear();    
                    } else {
                        ret.push_back(tmp.substr(start, end - start + 1));
                        tmp.clear();
                    }   
                }
            } else {
                tmp+=path[i];
            }    
        }
        if (0!=tmp.size()) {
            int start, end, i = 0;
            while (i<tmp.size() && ' ' == tmp[i]) i++;
            if (i == tmp.size()) goto finish;
            start = i;
            while (i< tmp.size() && ' '!=tmp[i]) i++;
            end = i; end --;
            if (0 == tmp.substr(start, end - start +1).compare("."))
                goto finish;
            if (0 == tmp.substr(start, end - start +1).compare("..")) {
                if (0!=ret.size())
                    ret.pop_back();
                goto finish;    
            } 
            ret.push_back(tmp.substr(start, end - start +1));
        }
finish:        
        if (0 == ret.size()) return "/";
        string r;
        for (int i = 0; i<ret.size(); i++) {
            r += "/";
            r += ret[i];
        }
        return r;
    }
};
