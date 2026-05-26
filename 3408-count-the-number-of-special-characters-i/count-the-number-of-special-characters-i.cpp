class Solution {
public:
    int specialChar(string word){
        unordered_map<char,bool>um;
        for(auto i: word){
            if('A'<=i && i<='Z'){
                um[i]= false;
            }
        }
        int cnt =0;
        for(auto i: word){
            if('a'<=i && i<='z'){
                char upper_pair = toupper(i);
                if(um.find(upper_pair)!=um.end() && um[i]== false){
                    cnt++;
                    um[i]= true;

                }
            }
        }
        return cnt;
    }
    int numberOfSpecialChars(string word) {
        return specialChar(word);
    }
};