class Solution {
public:
    // int firstOccurence(string haystack, string needle){
    //     int j = 0;
    //     int i = 0;
    //     while(i<haystack.size()){
    //         if(haystack[i]== needle[j]){
    //             i++;
    //             j++;
    //         }
    //         else{
    //             i++;
    //             j = 0;
    //         }
    //         if(j>=needle.size()) return i - needle.size();
    //     }
    //     return -1;
    // }
    int firstOccurence(string haystack,string needle){

    
        int haystackLen = haystack.size();
        int needleLen = needle.size();
        for(int i = 0;i<=haystackLen-needleLen;i++){
            for(int j = 0;j<needleLen;j++){
                if(needle[j] != haystack[i+j]){
                    break;
                }
                if(j == needleLen-1) return i;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        int answer = firstOccurence(haystack,needle);
        return answer;
    }
};