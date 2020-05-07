/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache
{
public:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int get(int key)
    {
        auto it = lru.find(key);
        if (it == lru.end())
            return -1;
        else
        {
            reorder(it);
            return it->second.first;
        }
    }

    void put(int key, int value)
    {
        auto it = lru.find(key);
        if (it == lru.end())
        {
            if (lru.size() == m_capacity)
            {
                lru.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
        }
        else
        {
            reorder(it);
        }
        lru[key] = {value, keys.begin()};
    }

private:
    using LI = list<int>;                  // list of keys
    using PII = pair<int, LI::iterator>;   // value & its position pair
    using HIPII = unordered_map<int, PII>; // keys and their value & position pairs

    // Making the queried key the first entry in the keys list
    void reorder(HIPII::iterator it)
    {
        int key = it->first;
        keys.erase(it->second.second);
        keys.push_front(key);
        it->second.second = keys.begin();
    }

    int m_capacity;
    LI keys;
    HIPII lru;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
