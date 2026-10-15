class Solution {
public:
    int stackMethod(string s){
        stack<char>store;
        for(auto i: s){
            if(i == '['){
                store.push(i);
            }else if(!store.empty() && store.top() == '['){
                store.pop();
            }
        }
        return (store.size()+1)/2;
    }
    int optimiseMethod(string s){
        int count = 0;
        for(auto i: s){
            if(i == '['){
                count++;
            }else if(count>0)count--;
        }
        return (count+1)/2;
    }
    int minSwaps(string s) {
        // return stackMethod(s);
        return optimiseMethod(s);
    }
};