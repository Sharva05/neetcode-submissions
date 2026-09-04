class Solution {
public:
    int jump(vector<int>& nums) {
        int futureDestination=0, steps=0, destination=0;
        for(int i=0; i<nums.size()-1; i++){
            futureDestination=max(futureDestination, i+nums[i]);
            if(i==destination){
                steps++;
                destination=futureDestination;
            }
        }
        return steps;
    }
};
