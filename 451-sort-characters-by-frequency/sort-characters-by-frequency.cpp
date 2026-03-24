class Solution {
public:
    string sortFrequency(string s){

        unordered_map<char,int> um;

        for(auto i: s){
            um[i]++;
        }

        string newString;

        while(!um.empty()){
            int maxCnt = INT_MIN;
            char maxEle;

            for(auto i: um){
                if(i.second > maxCnt){   // ✅ correct comparison
                    maxCnt = i.second;
                    maxEle = i.first;
                }
            }

            for(int i = 0; i < maxCnt; i++){
                newString += maxEle;
            }

            um.erase(maxEle);
        }

        return newString;
    }

    string frequencySort(string s) {
        return sortFrequency(s);
    }
};