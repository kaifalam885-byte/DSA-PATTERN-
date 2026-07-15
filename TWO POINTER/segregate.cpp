/*
Problem: Segregate 0s and 1s

Description:
Given an array containing only 0s and 1s, rearrange the array
so that all 0s appear before all 1s.

Pattern: Two Pointers

Approach:
1. Initialize one pointer (st) at the beginning of the array
   and another pointer (end) at the end.
2. If arr[st] is 0, it is already in the correct position,
   so move the start pointer forward.
3. If arr[st] is 1 and arr[end] is 0, swap both elements
   and move both pointers toward each other.
4. Otherwise, move the end pointer backward.
5. Continue until the two pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/
void segregate0and1(vector<int> &arr) {
        // code here
        int st=0;
        int end=arr.size()-1;
        while (st<end){
            if(arr[st]==0){
                st++;
            }else if(arr[st]==1 && arr[end]==0 ){
                swap(arr[st],arr[end]);
                st++;
                end--;
            }else{
                end--;
            }
        }
    }