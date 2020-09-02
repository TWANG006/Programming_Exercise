/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if(!root) return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int level_size = q.size();
            vector<int> level(level_size, 0);
            for(int i=0; i<level_size; i++)
            {
                Node* cur = q.front();
                q.pop();
                
                level[i] = cur->val;
                
                for(auto& j:cur->children)
                {
                    if(j) q.push(j);
                }
            }
            
            res.push_back(level);
        }
        
        return res;
    }
};
// @lc code=end

