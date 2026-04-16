class Solution {
public:
    void parenthesisGenerate(int n,vector<string>&genPar,string& temp,int opnBr,int clsBr){

        if(opnBr == n && clsBr==n){

            genPar.push_back(temp);

            return;

        }

        if(opnBr<n){

            temp.push_back('(');

            parenthesisGenerate(n,genPar,temp,opnBr+1,clsBr);

            temp.pop_back();

        }
        if(clsBr<opnBr){

            temp.push_back(')');

            parenthesisGenerate(n,genPar,temp,opnBr,clsBr+1);

            temp.pop_back();

        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>genPar;
        string temp = "";
        parenthesisGenerate(n,genPar,temp,0,0);
        return genPar;
    }
};