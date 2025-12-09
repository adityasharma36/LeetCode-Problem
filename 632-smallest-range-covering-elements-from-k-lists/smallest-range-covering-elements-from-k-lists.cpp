class Info{
    public:
        int data;
        int rIndex;
        int cIndex;

        Info(int val,int r,int c){
            data = val;
            rIndex= r;
            cIndex = c;
        }
};
class Compare{
    public:
        bool operator()(Info*a ,Info*b){
            return a->data> b->data;
        }
};
class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<Info* , vector<Info*> , Compare>pq;
        vector<int> ans;

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        int totalRow = nums.size();

        for(int i = 0;i<totalRow;i++){
            
            int ele = nums[i][0];

            Info * temp = new Info(ele,i,0);

            minVal = min(minVal , ele);

            maxVal = max(maxVal,ele);

            pq.push(temp);

        }

        int leftRange = minVal;
        int rightRange = maxVal;

        while(!pq.empty()){

            Info* temp = pq.top();
            pq.pop();

            int val = temp->data;
            int rInd = temp->rIndex;
            int cInd = temp->cIndex;

            minVal = val;

            if(maxVal -minVal < rightRange-leftRange){
                leftRange = minVal;
                rightRange = maxVal;
            }

            int totalCol = nums[rInd].size();

            if(cInd+1 < totalCol){

                int ele = nums[rInd][cInd + 1];

                Info * temp = new Info(ele, rInd, cInd + 1);

                maxVal = max(maxVal , ele);

                pq.push(temp);


            }else{
                break;
            }

        }

        ans.push_back(leftRange);
        ans.push_back(rightRange);

        return ans;


    
        
    }
};