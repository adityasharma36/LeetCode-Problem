class Solution {
public:
    void letterCombo(string digits,unordered_map<int,string>&um,vector<string>& answer,int index,string& ans){
        if(index== digits.size()){
            answer.push_back(ans);
            return;
        }

        int ele = (digits[index]-'0');
        if(um.find(ele)!= um.end()){
            string checking = um[ele];
            for(int i = 0;i<checking.size();i++){
                ans+=checking[i];
                letterCombo(digits,um,answer,index+1,ans);
                ans.pop_back();
        }
    }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
       ;


        unordered_map<int,string>um ={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

        vector<string>answer;
        string combo = "";
        letterCombo(digits,um,answer,0,combo);
        return answer;
    }
};