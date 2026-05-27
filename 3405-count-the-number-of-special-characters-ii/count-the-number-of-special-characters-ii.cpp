class Solution {
public:
    int specialChar(string word){
        unordered_map<char,int>upper,lower;
        int n = word.size();

        for(int i = 0;i<n;i++){
            if('a'<=word[i] && word[i]<='z') lower[word[i]] = i;
            else {
                if(upper.find(word[i]) == upper.end()){
                    upper[word[i]]= i;
                }
            }
        }
        int speChar = 0;
        for(auto i:lower){
            char ch = toupper(i.first);
            int ind = i.second;

            if(upper.find(ch)!= upper.end()){
                if(upper[ch]> ind){
                    speChar++;
                }
            }

        }
        return speChar;

    }
    int numberOfSpecialChars(string word) {
        return specialChar(word);
    }
};