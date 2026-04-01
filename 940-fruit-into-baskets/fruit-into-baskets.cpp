class Solution {
public:
    int fruitTotal(vector<int>& fruits){
        int cnt = 0;
        int left =0;
        unordered_map<int,int>um;
        for(int right = 0;right<fruits.size();right++){
            um[fruits[right]]++;
            while(um.size()>2){
                um[fruits[left]]--;
                if(um[fruits[left]]==0){
                    um.erase(fruits[left]);
                }
                left++;
            }
            cnt = max(cnt,right-left+1);
        }
        return cnt;
    }
    int totalFruit(vector<int>& fruits) {
        return fruitTotal(fruits);
    }
};