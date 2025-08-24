class Solution {
public:
    void stringReverse(vector<char>& s,int  start,int  end){
        if(start>=end){
            return;
        }
        swap(s[start],s[end]);
        stringReverse(s,start+1,end-1);
    }
    void reverseString(vector<char>& s) {

        int start  =0;
        int end = s.size()-1;
        stringReverse(s,start,end);
        
    }
};