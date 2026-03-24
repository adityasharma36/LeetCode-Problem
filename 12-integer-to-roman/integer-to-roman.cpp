class Solution {
public:
    string intToRom(int num){
       string roman[]= {"M", "CM", "D", "CD","C","XC","L","XL","X","IX","V","IV","I"};
        int interger[]= {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romanStri;
        for(int i = 0;i<13;i++){
            while(num>=interger[i]){
                romanStri+=roman[i];
                num-=interger[i];
            }
        }
        return romanStri;
    }
    string intToRoman(int num) {
        return intToRom(num);
    }
};