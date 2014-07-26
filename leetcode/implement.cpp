
Implement strStr()
Total Accepted: 14980 Total Submissions: 69209

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == needle || NULL == haystack) return NULL; 
        if (strlen(haystack) < strlen(needle))
            return NULL;
        int loc = 0;
        for (loc = 0; loc <= strlen(haystack)-strlen(needle); loc++) {
            int wrong = 0;
            for (int i = 0; i<strlen(needle); i++) {
                if (haystack[loc+i] != needle[i]) {
                    wrong = 1;
                    break;
                }
            }
            if (0 == wrong)
                return &haystack[loc];
        }
        return NULL;
    }
};
