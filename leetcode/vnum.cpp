
Valid Number
Total Accepted: 8505 Total Submissions: 78682

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 

class Solution {
public:
    bool isNumber(const char *s) {
       if (NULL == s) return false;
       char *ss = (char*)malloc(strlen(s) + 1);
       memset(ss, 0, strlen(s) + 1);
       strncpy(ss, s, strlen(s));
       char *left, *right, *loc;
       int has_dot = 0;
       loc = ss;
       while ('\0' != *loc && ' ' == *loc) loc++;
       if ('\0' == *loc) return false;
       int size = strlen(ss); char* tail = (char*)ss + strlen(ss) - 1;
       while (' ' == *tail) {
           *tail = '\0';
           tail--;
       }
       if ('+' == *loc || '-' == *loc) loc++;
       else if ('.' == *loc) {
           loc++;
           has_dot = 1;
       }
       if ('\0' == *loc) return false;
       if (0 == has_dot && '.' == *loc) {
           loc++;
           if ('\0' == *loc || *loc <'0' || *loc >'9') return false;
           while ('\0' != *loc && *loc >= '0' && *loc <='9') loc++;
           if ('\0' == *loc) return true;
           if ('e' == *loc) {
               loc++;
               if ('\0' == *loc) return false;
               if ('+' == *loc || '-' == *loc) loc++;
               if (*loc < '0' || *loc > '9') return false;
               while ('\0' != *loc && *loc >= '0' && *loc <='9') loc++;
               if ('\0' == *loc) return true;
               return false;
           }
           return false;
       }
       if (*loc < '0' || *loc > '9') return false;
       while ('\0'!=*loc && *loc >='0' && *loc <='9') loc++;
       if ('\0' == *loc) return true;
       if ('.' == *loc && 1 == has_dot) return false;
       if ('.' == *loc) {
           loc++;
           if ('\0' == *loc) return true;
           if ('e' == *loc) {
               loc++;
               if ('\0' == *loc) return false;
               if ('+' == *loc || '-' == *loc) loc++;
               if (*loc < '0' || *loc > '9') return false;
               while ('\0' != *loc && *loc >='0' && *loc <= '9') loc++;
               if ('\0' == *loc) return true;
               return false;
           }
           if (*loc < '0' || *loc >'9') return false;
           while ('\0'!=*loc && *loc >='0' && *loc <='9') loc++;
           if ('\0' == *loc) return true;
           if ('e' == *loc) {
               loc++;
               if ('\0' == *loc) return false;
               if ('+' == *loc || '-' == *loc) loc++;
               if ('\0' == *loc) return false;
               if (*loc < '0' || *loc > '9') return false;
               while ('\0' != *loc && *loc >='0' && *loc <= '9') loc++;
               if ('\0' == *loc) return true;
               return false;
           }
           return false;
       }
       
       if ('e' == *loc) {
           loc++;
           if ('\0' == *loc) return false;
           if ('+' == *loc || '-' == *loc) loc++;
           if ('\0' == *loc) return false;
           char* t = loc;
           while ('\0' != *t) {
               if ('.' == *t) return false;
               if ('e' == *t) return false;
               t++;
           }
           /*
           if (*loc < '0' || *loc > '9') return false;
           while ('\0' != *loc && *loc >= '0' && *loc <= '9') loc++;
           if ('\0' == *loc) return true;
           return false;*/
           return isNumber(loc);
       }
       
       return false;
       
    }
};
