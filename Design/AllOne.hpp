//
// Created by SnirN on 2/3/2025.
//

#ifndef LEETCODE_150_C___ALLONE_HPP
#define LEETCODE_150_C___ALLONE_HPP

#include <string>
#include <unordered_map>
#include <utility>

class AllOne {
  using Node = std::pair<std::string, int>;
public:
  AllOne() {

  }

  void handleNewKey(std::string &key)
  {
    auto newNode = new Node();
    newNode->first = key;
    newNode->second = 1;
    keysCounterMap.insert({key, newNode});
    nodeLinkList.push_front(newNode);
  }

  void swapNodesAtMap(Node* node1, Node* node2)
  {
    //Delete and insert again
    keysCounterMap.erase(node1->first);
    keysCounterMap.erase(node2->first);
    keysCounterMap.insert({node1->first, node1});
    keysCounterMap.insert({node2->first, node2});
  }

  void swapNodesAtList(Node* node1, Node* node2)
  {
    //swap values at list
    Node tempNode = *node1;
    *node1 = *node2;
    *node2 = tempNode;
  }

  void swapNodes(Node* node1, Node* node2)
  {
    swapNodesAtList(node1, node2);
    swapNodesAtMap(node1, node2);
  }

  void updateMinOrMaxIfNeeded()
  {
    auto itStart = nodeLinkList.begin();
    auto itEnd = nodeLinkList.end();

    Node *current = *itStart;
    Node *next = *(++itStart);
    if (current->second > next->second){
      swapNodes(current, next);
    }

    current = *(--itEnd), next = *(--itEnd);
    if (current->second < next->second){
      swapNodes(current, next);
    }
  }

  void handleExistingKey(std::string &key)
  {
    auto it = keysCounterMap.find(key);
    it->second->second++;
    Node* maxNode = nodeLinkList.back();
    //handle max swap
    if(maxNode->second < it->second->second)
    {
      swapNodes(maxNode, it->second);
    }
    updateMinOrMaxIfNeeded();
  }

  void inc(std::string key) {
    auto it = keysCounterMap.find(key);
    if(it != keysCounterMap.end()) //exists
    {
      handleExistingKey(key);
    }
    else
    {
      handleNewKey(key);
    }
  }

  void updateMinValIfNeeded(std::string &key)
  {
    auto it = keysCounterMap.find(key);
    it->second->second--;
    Node* minNode = nodeLinkList.front();
    if(minNode->second > it->second->second)
    {
      swapNodes(minNode, it->second);
    }
  }

  void dec(std::string key) {
    updateMinValIfNeeded(key);
    auto it = keysCounterMap.find(key);
    if (it->second->second == 0){
      keysCounterMap.erase(key);
      nodeLinkList.pop_front();
    }
    updateMinOrMaxIfNeeded();
  }

  std::string getMaxKey() {
    if(nodeLinkList.empty())
    {
      return "";
    }
    return nodeLinkList.back()->first;
  }

  std::string getMinKey() {
    if(nodeLinkList.empty())
    {
      return "";
    }
    return nodeLinkList.front()->first;
  }

private:
  std::unordered_map<std::string, Node*> keysCounterMap;
  std::list<Node*> nodeLinkList;
};



void testAllOne()
{
  AllOne* obj = new AllOne();
  obj->inc("a");
  obj->inc("b");
  obj->inc("c");
  obj->inc("d");
  obj->inc("a");
  obj->inc("b");
  obj->inc("c");
  obj->inc("d");
  obj->inc("c");
  obj->inc("d");
  obj->inc("d");
  obj->inc("a");
  obj->getMinKey();



  obj->inc("hello");
  obj->inc("hello");
  std::string param_3 = obj->getMaxKey();
  std::string param_4 = obj->getMinKey();
  obj->inc("leet");
  param_3 = obj->getMaxKey();
  param_4 = obj->getMinKey();
  obj->dec("hello");
  obj->dec("hello");
  param_3 = obj->getMaxKey();
  param_4 = obj->getMinKey();
  obj->inc("hi");
  param_3 = obj->getMaxKey();
  param_4 = obj->getMinKey();
  obj->inc("hi");
  param_3 = obj->getMaxKey();
  param_4 = obj->getMinKey();
}
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
#endif // LEETCODE_150_C___ALLONE_HPP
