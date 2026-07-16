// # Squares of a Sorted Array leetcode(977)

// ## Question Explanation

// Given an integer array `nums` sorted in **non-decreasing order**, we need to square every element and return a new array containing these squares in **non-decreasing order**.

// For example:

// Input: `nums = [-4, -1, 0, 3, 10]`

// After squaring: `[16, 1, 0, 9, 100]`

// Expected Output: `[0, 1, 9, 16, 100]`

// The main challenge is that simply squaring the elements does not keep the array sorted because negative numbers can produce larger squares.

// ## Approach

// 1. Create two separate vectors:

//    * `a` for negative elements.
//    * `b` for non-negative elements.

// 2. Traverse the original array and separate negative and non-negative elements into `a` and `b`.

// 3. Square all the elements of `a`. Since the negative numbers were originally sorted, their squares will be in reverse order. Reverse `a` to get the squares in ascending order.

// 4. Square all the elements of `b`. They will remain in ascending order.

// 5. Now both `a` and `b` are sorted. Use the **two-pointer merge technique** to compare elements

 vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        vector<int>a;
        vector<int>b;

        for(int i=0;i<nums.size();i++){    //use to seprate the negative element in a and postive element in b
            if(nums[i]<0){
                a.push_back(nums[i]);
            }else{
                b.push_back(nums[i]);
            }
        }
        for(int i=0;i<a.size();i++){//use to squaring and reversing the negative elements
            a[i]=a[i]*a[i];
        }
        reverse(a.begin(),a.end());


for(int i=0;i<b.size();i++){ //use to squaring the positive elements
    b[i]=b[i]*b[i];
}


int i=0;
int j=0;
while(i<a.size()&& j<b.size()){
    if(a[i]<b[j]){
        ans.push_back(a[i]);
        i++;
    }else{
         ans.push_back(b[j]);
         j++;
    }
}
while(j<b.size()){
    ans.push_back(b[j]);
    j++;
}
while(i<a.size()){
    ans.push_back(a[i]);
    i++;
}


    return ans;    
    }