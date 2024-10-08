//"Search Insertion Point"
//Following is the link to the Question

//https ://leetcode.com/problems/search-insert-position/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Initialize two pointers for the beginning and end of the array
        int left = 0;
        int right = nums.size() - 1;

        // Continue to search while the left pointer is less than or equal to the right pointer
        while (left <= right) {
            // Calculate the middle index to avoid overflow and ensure proper mid calculation
            int mid = left + (right - left) / 2;

            // If the middle element is the target, return its index
            if (nums[mid] == target) {
                return mid;
            }

            // If the middle element is less than the target, search the right half
            if (nums[mid] < target) {
                left = mid + 1;
            }
            // Otherwise, search the left half
            else {
                right = mid - 1;
            }
        }

        // If the target is not found, return the position where it can be inserted,
        // which will be the index pointed to by 'left'
        return left;
    }
};

//
//Time Complexity :
//Best O(1) : The best case occurs if the target is at the middle of the array during the first iteration.
//Worst O(logn): Binary search halves the search space with each iteration, so the time complexity is logarithmic based on the size of the array n.
//
//    Space Complexity O(1) : The space complexity is constant because the algorithm only uses a few extra variables(like left, right, and mid) for its operation, regardless of the input size.