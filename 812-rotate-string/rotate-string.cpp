class Solution {
public:
    bool stringRotate(string s, string g){
        if(s.size()!= g.size()) return false;
        s = s+s;
        cout<<s;
        return s.find(g) != string::npos;
    }
    bool rotateString(string s, string goal) {
        return stringRotate(s,goal);
    }
};