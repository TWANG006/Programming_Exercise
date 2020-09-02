/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (52.14%)
 * Likes:    1382
 * Dislikes: 70
 * Total Accepted:    108.4K
 * Total Submissions: 207.4K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree
 * structure.
 * 
 * The encoded string should be as compact as possible.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        
        serialize(root, out);
        
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        
        return deserialize(in);
    }
    
    
private:
    void serialize(TreeNode* root, ostringstream &out)
    {
        if(root!=nullptr)
        {
            out<<root->val<<' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out<<"N ";
        }
    }
    
    
    TreeNode* deserialize(istringstream &in)
    {
        string s;
        in>>s;
        
        if(s=="N")
            return nullptr;
        
        TreeNode* cur = new TreeNode(stoi(s));
        cur->left = deserialize(in);
        cur->right = deserialize(in);
        
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

