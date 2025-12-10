class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i= 0;i<arr.size();i++){
            um[arr[i]]++;
        }

        unordered_map<int,bool> up;

        for(auto i : um){
            int secondVal = i.second;
            if(up.find(secondVal)!= up.end()) return false;

            else{
                up[secondVal]= true;
            }
        }
        return true;
    }
};