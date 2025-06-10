class Solution { // Time Complexity O((m+n)log(m+n)) 
// space complexity O(1) as no extra storage needed
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>merged;
        for (int i = m, j = 0; j < n; j++) { // 2nd approach: adding elements of the second vector
        // from the last element of nums1
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());
        //nums1 = merged; // fully copying in new vec
        // stack<int> st;
        // int i = 0;
        // while (nums1.size() == 0) {
        //     if (nums1[i] != 0) st.push(nums1[i]);
        //     nums1.erase(nums1.begin() + i);
        //     i++;
        // }
    }
};