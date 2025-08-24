class Solution {
public:
    // int answer(string s){
    //     string ans = "";
    //     char sign = '+';
    //     int index = 0;
    //     int final = -1;
    //     for(int i = 0;i<s.size();i++){
    //         if(s[i]=='-'){
    //             sign = s[i];
    //             index++;
    //         }else if(s[i]==' '){
    //             index++;
    //         }else if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z')){
    //             ans = s.substr(index ,i);
    //             final = i;
    //             break;
    //         }
    //     }

    //     ans = s.substr(index ,final);

    //     cout<<ans<<endl;
    //     return 0;

    // }

    int answer(string s){
        int ans = 0 , index = 0;
        int sign = 1;
        while(s[index]==' '){
            index++;
        }
        if( index < s.size() &&(s[index]== '-' || s[index]=='+')){
            sign = s[index]=='-'? -1 : 1;
            index++;
        }

        while(index< s.size() && isdigit(s[index])){

            if((ans > INT_MAX/10) || (ans == INT_MAX/10  && s[index] > '7') ){
                return sign == -1 ? INT_MIN: INT_MAX;
            }
            ans = ans * 10 + (s[index++]-'0');
        }
        return ans*sign;
    }
    int myAtoi(string s) {
        return answer(s);
    }
};