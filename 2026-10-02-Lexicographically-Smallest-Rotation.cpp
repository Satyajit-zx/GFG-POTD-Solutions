class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();
        
        // Double the string
        string str = s + s;
        
        int i = 0, j = 1, k = 0;
        
        while (i < n && j < n && k < n) {
            if (str[i + k] == str[j + k]) {
                k++;
                continue;
            }
            
            if (str[i + k] > str[j + k]) {
                i = i + k + 1;
                if (i <= j)
                    i = j + 1;
            } 
            else {
                j = j + k + 1;
                if (j <= i)
                    j = i + 1;
            }
            
            k = 0;
        }
        
        int start = min(i, j);
        return str.substr(start, n);
    }
};
