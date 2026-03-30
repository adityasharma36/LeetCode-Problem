class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int count = 1;
        string temp = a;
        int n = a.size(), m = b.size();
        while(n<m)
        {
            count++;
            a += temp;
            n = a.size();
        }
        if(a.find(b)!=string::npos) return count;

        a += temp;
        if(a.find(b)!=string::npos) return count+1;//handles boundary overlap

        return -1;
    }
};
