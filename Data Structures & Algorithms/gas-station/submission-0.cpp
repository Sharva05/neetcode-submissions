class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, startTank=0, totGas=0, totCost=0;
        for(int i=0; i<gas.size(); i++){
            startTank+=gas[i]-cost[i];
            if(startTank<0){
                start=i+1;
                startTank=0;
            }
            totGas+=gas[i];
            totCost+=cost[i];
        }
        return(totGas-totCost<0)?-1:start;
    }
};
