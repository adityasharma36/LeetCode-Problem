class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int requireGas = 0;
        int n = gas.size();
        int currentGas = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            currentGas = gas[i]-cost[i]+ currentGas;
            if(currentGas<0){
                requireGas+=abs(currentGas);
                currentGas=0;
                j = i+1;
            }
        }
        if(currentGas >= requireGas) return j;

        return -1;
    }
};