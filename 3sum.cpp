// 3Sum

// ### Problem

// Given an integer array `nums`, find all unique triplets `[nums[i], nums[j], nums[k]]` such that:

// `nums[i] + nums[j] + nums[k] = 0`

// The solution should not contain duplicate triplets.

// ### Approach

// 1. Sort the array.
// 2. Iterate through the array and fix one element at index `i`.
// 3. Use two pointers:

//    * `left = i + 1`
//    * `right = nums.size() - 1`
// 4. Calculate the sum of the three elements.

//    * If the sum is `0`, add the triplet to the result.
//    * If the sum is less than `0`, move the `left` pointer forward.
//    * If the sum is greater than `0`, move the `right` pointer backward.
// 5. Skip duplicate elements to ensure that only unique triplets are added.

// Time Complexity

// **O(n²)** — Sorting takes `O(n log n)`, and the two-pointer traversal takes `O(n²)` overall.

// ### Space Complexity

// **O(1)** auxiliary space, excluding the space used to store the output.

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate first elements
        

        int st = i + 1;
        int end = n - 1;

        while (st < end) {
            int sum = nums[i] + nums[st] + nums[end];

            if (sum == 0) {
                ans.push_back({nums[i], nums[st], nums[end]});

                st++;
                end--;

                // Skip duplicate second elements
                while (st < end && nums[st] == nums[st - 1])
                    st++;

                // Skip duplicate third elements
                while (st < end && nums[end] == nums[end + 1])
                    end--;
            }
            else if (sum > 0) {
                end--;
            }
            else {
                st++;
            }
        }
    }

    return ans;
}
   