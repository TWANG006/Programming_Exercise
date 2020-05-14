/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        in.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        while (in.size() > 1)
        {
            out.push(in.front());
            in.pop();
        }
        int res = in.front();
        in.pop();

        queue<int> tmp = in;
        in = out;
        out = tmp;

        return res;
    }

    /** Get the top element. */
    int top()
    {
        while (in.size() > 1)
        {
            out.push(in.front());
            in.pop();
        }
        
        int res = in.front();
        out.push(res);
        in.pop();

        queue<int> tmp = in;
        in = out;
        out = tmp;

        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return in.empty();
    }

private:
    queue<int> in;
    queue<int> out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
