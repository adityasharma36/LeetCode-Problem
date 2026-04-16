class Solution {
public:
    void stringValid(int n,vector<string>&ans,string& temp){

        if(temp.size()==n){

            ans.push_back(temp);

            return;
            
        }

        temp.push_back('1');

        stringValid(n,ans,temp);

        temp.pop_back();

        if(temp.empty() ||  temp.back()!='0'){

            temp.push_back('0');

            stringValid(n,ans,temp);

            temp.pop_back();

        }

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        int i = 0;
        string temp = "";
        stringValid(n,ans,temp);
        return ans;
    }
};