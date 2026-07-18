// # 3Sum Closest (LEETCODE 16)

// ## Problem

// Given an integer array `nums` and an integer `target`, find three integers in `nums` such that their sum is closest to the target.

// Return the sum of the three integers.

// ## Approach

// 1. First, sort the array so that we can efficiently use the two-pointer technique.
// 2. Iterate through the array using `i` and fix `nums[i]` as the first element of the triplet.
// 3. Use two pointers:

//    * `st = i + 1`
//    * `end = nums.size() - 1`
// 4. Calculate the sum of the three elements:
//    `sum = nums[i] + nums[st] + nums[end]`
// 5. Calculate the absolute difference between the current sum and the target.
// 6. Keep track of the minimum difference found so far in `ans` and store the corresponding sum in `sumans`.
// 7. If the current sum is smaller than the target, increment `st` to increase the sum.
// 8. If the current sum is greater than the target, decrement `end` to decrease the sum.
// 9. If the current sum is exactly equal to the target, return the sum immediately because the difference is `0`, which is the closest possible value.

// ## Time Complexity

// * Sorting: `O(n log n)`
// * Two-pointer traversal for each element: `O(n²)`

// Overall Time Complexity: **O(n²)**

// ## Space Complexity

// **O(1)** auxiliary space, excluding the space used internally by the sorting algorithm.


int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int sumans=0;
        
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int st=i+1;
            int end=nums.size()-1; 
           
            while(st<end){
                 int sum=nums[i]+nums[st]+nums[end];
                int diff=abs(sum-target);

                if(target>sum){
                    st++;
                    
                }
                else if(target==sum){
                    return sum;

                }
                
                else{
                  
                    end--;
                }

                ans=min(diff,ans);
                  if (ans == diff) {
                sumans = sum;
            }
                
               
            }
        }
        
       return sumans; 
    }