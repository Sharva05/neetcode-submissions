class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1);

        int t=n1+n2, h=(t+1)/2;
        
        int l=0, r=n1;

        while(l<=r) {
            int i=l+(r-l)/2;
            int j=h-i;

            int l1=(i==0)?INT_MIN:nums1[i-1];
            int l2=(j==0)?INT_MIN:nums2[j-1];

            int r1=(i==n1)?INT_MAX:nums1[i];
            int r2=(j==n2)?INT_MAX:nums2[j];

            if(l1 <= r2 && l2 <= r1) {
                if(t%2 == 0) 
                    return (double)(max(l1, l2)+min(r1, r2))/2.0;
                
                return (double)(max(l1, l2));
            }
            else if(l1 > r2) r=i-1;//we need to take less i elements from small array
            else l=i+1;
        }
        return 0.0;
    }
};
