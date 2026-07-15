/*
Problem: Two Sum II - Input Array Is Sorted

Description:
Given a 1-indexed array of integers 'numbers' that is already sorted
in non-decreasing order, find two numbers such that they add up to
a specific target number.

Return the indices of the two numbers, added by one, as an integer array.

Pattern: Two Pointers

Approach:
1. Place one pointer at the start and another at the end.
2. Calculate the sum of both elements.
3. If sum == target, return their 1-based indices.
4. If sum > target, move the end pointer to the left.
5. If sum < target, move the start pointer to the right.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
        int st=0;
        int end=numbers.size()-1;
        while(st<end){
            int sum=numbers[st]+numbers[end];
            if(sum==target){
                return {st+1,end+1};
            }else if(sum>target){
                end--;
            }else{
                st++;
            }
        }
      return {};  
    }
