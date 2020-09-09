/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (57.99%)
 * Likes:    676
 * Dislikes: 128
 * Total Accepted:    73.3K
 * Total Submissions: 126.1K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        if(root==nullptr) return {};
        
        unordered_map<int, int> sum_and_count;
        int max_count = INT_MIN;
        
        countSubtreeSums(root, sum_and_count, max_count);
        
        vector<int> res;
        
        for(const auto & i: sum_and_count)
        {
            if(i.second == max_count) res.push_back(i.first);
        }
        
        return res;
    }
    
    int countSubtreeSums(TreeNode* root, unordered_map<int, int>& sum_and_count, int& max_count)
    {
        if(root==nullptr) return 0;
        
        int sum = countSubtreeSums(root->right, sum_and_count, max_count) + countSubtreeSums(root->left, sum_and_count, max_count) + root->val;
                
        sum_and_count[sum]++;
        
        max_count = max(max_count, sum_and_count[sum]);
        
        return sum;
    }
};
// @lc code=end

