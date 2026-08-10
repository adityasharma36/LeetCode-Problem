class Solution {
public:
    int ans = 0;
    int n;
    void maxFind(string answerKey){
        int i  = 0;
        int total = 0;
        while(i<n){
            if(answerKey[i]== 'T'){
                i++;
                total = 1;
                while(i<n && answerKey[i]== 'T'){
                    total++;
                    i++;
                }
                ans = max(total,ans);

            }else{
                i++;
                total = 1;
                while(i<n && answerKey[i]== 'F'){
                    total++;
                    i++;
                }
                ans = max(total,ans);
            }
        }
    }
    void solve(int index, string answerKey,int k){
        maxFind(answerKey);
        if(index >=n || k<=0) return;

        answerKey[index]= answerKey[index] == 'T' ? 'F' : 'T';
        solve(index+1,answerKey,k-1);
        answerKey[index] = answerKey[index] == 'T' ? 'F': 'T';
        solve(index+1,answerKey,k); 
    }
    int secondMethod(string answerKey,int k){
        int countF = 0;
        int i = 0;
        int j = 0;
        int ans1 = 0;
        int n = answerKey.size();
        while(j<n){
            if(answerKey[j]== 'F'){
                countF++;
            }
            while(countF>k){
                if(answerKey[i]=='F'){
                    countF--;
                }
                i++;
            }
            ans1 = max(ans1,j-i+1);
            j++;
        }
        i =0;
        j = 0;
        int ans2 = 0;
        int countT = 0;
        while(j<n){
            if(answerKey[j] == 'T'){
                countT++;
            }
            while(countT>k){
                if(answerKey[i]=='T'){
                    countT--;
                }
                i++;
            }
            ans2 = max(ans2,j-i+1);
            j++;
        }
        return max(ans1,ans2);
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        // int index = 0;
        // n = answerKey.size();
        // solve(index,answerKey,k);
        
        // return ans;   


        return secondMethod(answerKey,k);
    }
};