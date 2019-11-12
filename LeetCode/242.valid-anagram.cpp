/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (54.14%)
 * Likes:    926
 * Dislikes: 121
 * Total Accepted:    423.7K
 * Total Submissions: 782.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        return isAnagram_linear(s,t);
    }

    bool isAnagram_linear(const string & s, const string & t){
        vector<int> counter(26, 0);

        for(int i=0; i<s.size(); i++){
            counter[s[i]-'a']++;
            counter[t[i]-'a']--;
        }

        for(int i=0; i<26; i++){
            if (counter[i]!=0)
                return false;
        }
        return true;
    }

    bool isAnagram_map(string& s, string &t){
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for(auto & i:s){
            s_map[i] +=1;
        }
        for(auto & i:t){
            t_map[i] +=1;
        }
        
        return s_map == t_map;
    }
};
// @lc code=end

