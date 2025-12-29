class Solution {
public:
    int fruitTotal(vector<int>& fruit){
        // if(fruit.size()<2) return -1;

        unordered_map<int,int>um;
        int left = 0;
        int ans = -1;

        for(int right = 0;right<fruit.size();right++){

            um[fruit[right]]++;

            while(um.size()>2){
                um[fruit[left]]--;
                if(um[fruit[left]]==0){
                    um.erase(fruit[left]);
                }
                left++;
            }

        
                ans = max(ans,right-left+1);
     
        }
        return ans;
    }
    int totalFruit(vector<int>& fruits) {
        return fruitTotal(fruits);
    }
};