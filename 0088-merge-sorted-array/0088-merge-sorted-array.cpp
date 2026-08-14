class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m+n);
        int i = 0, j = 0;
        int index = 0;

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                result[index] = nums1[i];
                index++;
                i++;
            }
            else if(nums2[j] <= nums1[i]){
                result[index] = nums2[j];
                index++;
                j++;
            }
        }

        while(i < m) {
            result[index] = nums1[i];
            index++;
            i++;
        }
        while(j < n) {
            result[index] = nums2[j];
            index++;
            j++;
        }

        nums1 = result;
    }
};