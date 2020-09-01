/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
            out<<root->val<<' ' ;
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out<<"N ";
        }
    }
    
    TreeNode* deserialize(istringstream& in)
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

