/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 *
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (47.37%)
 * Likes:    427
 * Dislikes: 206
 * Total Accepted:    48.7K
 * Total Submissions: 102.9K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 * 
 * Example:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * Note: 
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 * 
 */

// @lc code=start
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {      
        m_k = k;
        for(int i=0; i<nums.size(); i++){
            if(i<k)
                m_minK.push(nums[i]);
            else{
                if(nums[i]>m_minK.top()){
                    m_minK.pop();
                    m_minK.push(nums[i]);
                }                    
            }
        }
        
    }
    
    int add(int val) {
        if(m_minK.size()<m_k)
        {
            m_minK.push(val);
            return m_minK.top();
        }
        
        if(val<=m_minK.top()){
            return m_minK.top();
        }
        else{
            m_minK.pop();
            m_minK.push(val);
            return m_minK.top();
        }
    }
    
    priority_queue<int, vector<int>, greater<int>> m_minK;
    int m_k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

