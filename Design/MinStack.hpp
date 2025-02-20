//
// Created by SnirN on 2/20/2025.
//

#ifndef LEETCODE_150_C___MINSTACK_HPP
#define LEETCODE_150_C___MINSTACK_HPP
#include <stack>
#include <utility>

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    int currMin = INT32_MAX;
    if(!minStack.empty()){
      currMin = minStack.top().second;
    }

    if (val < currMin) {
      currMin = val;
    }
    minStack.emplace(val, currMin);
  }

  void pop() {
    minStack.pop();
  }

  int top() {
    return minStack.top().first;
  }

  int getMin() { return minStack.top().second; }

private:
  std::stack<std::pair<int, int>> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void testMinStack() {
  MinStack *obj = new MinStack();
  obj->push(5);
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  obj->push(3);
  obj->push(4);
  obj->push(1);
  obj->push(2);
  param_3 = obj->top();
  param_4 = obj->getMin();
  obj->pop();
  obj->pop();
  obj->pop();
  param_3 = obj->top();
  param_4 = obj->getMin();
}

#endif // LEETCODE_150_C___MINSTACK_HPP
