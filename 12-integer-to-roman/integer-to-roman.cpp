class Solution {
public:
    string intergerToRoman(int num){
        string roman[]= {"M", "CM", "D", "CD","C","XC","L","XL","X","IX","V","IV","I"};
        int interger[]= {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string answer;

        for(int i = 0;i<13;i++){

            while(num>=interger[i]){
                
                num-=interger[i];
                answer+=roman[i];
            }
        }
        return answer;
    }
    string intToRoman(int num) {
        string answer = intergerToRoman(num);
        return answer;
    }
};