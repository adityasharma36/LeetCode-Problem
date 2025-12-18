// class Node{
//     public:
//         char val;
//         unordered_map<char,Node*> um;
//         bool isTerminal;

//         Node(char data){
//             this->val = data;
//             this->isTerminal = false;
//         }
// };
// void valueInsert(Node* head,string s){
//     // base case;

//     if(s.length()==0){
//         head->isTerminal = true;
//         return;
//     }

//     // ek case me solve karunga
//     char firstEle = s[0];
//     Node* child;

//     if(head->um.find(firstEle) != head->um.end()){
//         child = head->um[firstEle];
//     }else{
//         child = new Node(firstEle);
//         head->um[firstEle]= child;
//     }

//     valueInsert(child,s.substr(1));
// }
// void findLCP(Node* head,string & ans){
//     if(head->isTerminal == true){
//         return;
//     }

//     Node* child;
//     if(head->um.size() == 1){
//         for(auto i: head->um){
//             char fir = i.first;
//             ans.push_back(fir);
//             child = i.second;
//         }
//     }else{
//         return;
//     }
//     findLCP(child,ans);
// }
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //    Node* head = new Node('-');
        // string ans = "";
        // for(auto i: strs){
        //     valueInsert(head,i);
        // }
        // findLCP(head,ans);
    
        string ans = strs[0];

        for(int i= 1;i<strs.size();i++){

            string secondStr = strs[i];

            int j = 0;
            while(j<ans.size() && j<secondStr.size() && ans[j]== secondStr[j]){
                j++;
            }
            ans = ans.substr(0,j);

            if(ans.empty()) return "";
        }
        return ans;
    }
};