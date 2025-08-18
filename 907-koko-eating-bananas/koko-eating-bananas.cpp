class Solution {
public:
    int largestNumb(vector<int>& piles){

        int largestNumber = INT_MIN;

        for(int i = 0;i<piles.size();i++){

            largestNumber = max(largestNumber,piles[i]);

        }

        return largestNumber;

    }
    long long minimumHours(vector<int>&piles,int divisor){

        long long hours = 0;
        
        for(int i = 0;i<piles.size();i++){

            // double answer = double(piles[i]/divisor);

           hours += ((long long)piles[i] + divisor - 1) / divisor;

        
        }
        
        return hours;
    
    }

    int kokoEating(vector<int>& piles,int h){
    
        int start = 1;
    
        int end = largestNumb(piles);

        int miniHours = INT_MAX;
    
        while(start<=end){
    
            int mid = start + (end-start)/2;
    
            long long overAll = minimumHours(piles,mid);
    
            if(overAll<=h){
    
                miniHours = min(miniHours,mid);
    
                end = mid -1;
    
            }else{
    
                start = mid + 1;
    
            }
    
        }
    
        return miniHours;
    
    }

    int minEatingSpeed(vector<int>& piles, int h) {
    
        int minBanana = kokoEating(piles,h);

        return minBanana;
    }
};