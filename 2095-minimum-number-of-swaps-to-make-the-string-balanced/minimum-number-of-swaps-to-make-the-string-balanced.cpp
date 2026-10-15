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
    int minSwaps(string s) {
        return stackMethod(s);
    }
};