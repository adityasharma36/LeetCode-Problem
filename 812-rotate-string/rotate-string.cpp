class Solution {
public:
    // bool stringRotate(string s, string goal){
        // if(s.size()!= goal.size()) return false;
    //     int count = 0;
    //     string finding ;
    //     for(int i= 0;i<s.size();i++){
    //         finding+=s[i];

    //         if(goal.find(finding) == string::npos){
    //             count++;
    //             finding = s[i];
    //         }

    //     }
    //     if(count>1) return false;

    //     return true;
    // }

    bool stringRotate(string s,string goal){
        if(s.size()!= goal.size()) return false;

        string newString = s+s;

        if(newString.find(goal) != string::npos){
            return true;
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        bool answer = stringRotate(s,goal);
        return answer;
    }
};