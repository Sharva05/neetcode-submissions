class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        int l=0, r=n-1, lBuc=height[0], rBuc=height[n-1], t=0;

        while(l<=r){
            lBuc=max(lBuc, height[l]);
            rBuc=max(rBuc, height[r]);
            if(lBuc<rBuc){
                t+=lBuc-height[l++];
            }
            else{
                t+=rBuc-height[r--];
            }
        }
        return t;
    }
};
