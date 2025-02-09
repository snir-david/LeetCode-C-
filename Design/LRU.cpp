//
// Created by SnirN on 1/28/2025.
//
#include <unordered_map>
#include <list>

using Node = std::pair<int, int>;

class LRUCache {
public:
  LRUCache(int capacity) {
    m_capacity = capacity;
  }


  void deleteNodeFromList(Node *node)
  {
    listOfPairs.remove(node);
    lruNodes.erase(node->first);
  }


  void insertNodeToHeadOfTheList(Node *node){
    listOfPairs.push_front(node);
    lruNodes.insert({node->first, node});
  }

  void deleteLRU(){
    auto node = listOfPairs.back();
    lruNodes.erase(node->first);
    listOfPairs.pop_back();
    delete node;
  }


  void put(int key, int value) {
    Node* node = nullptr;
    auto it = lruNodes.find(key);
    if(it != lruNodes.end())
    {
     node = it->second;
     node->second = value; //update value for the key
     deleteNodeFromList(node); //remove from list (will be head soon)
    }
    //handle case of full cache
    if(lruNodes.size() >= m_capacity)
    {
      deleteLRU();
    }
  //if node didn't exists, create it
    if(!node)
      node = new Node(key, value);

    insertNodeToHeadOfTheList(node);
  }

  int get(int key) {
    auto it = lruNodes.find(key);
    if(it == lruNodes.end()){
      return -1;
    }
    Node *node = it->second;
    //move to beginning of the list
    deleteNodeFromList(node);
    insertNodeToHeadOfTheList(node);
    return node->second;
  }

private:
  int m_capacity = 0;
  std::unordered_map<int , Node*> lruNodes;
  std::list<Node*> listOfPairs;
};


void testLRU()
{
  auto lru = new LRUCache(2);
  int res =0;
  res = lru->get(2);
  lru->put(2,6);
  res = lru->get(1);
  lru->put(1,5);
  lru->put(1,2);
  res = lru->get(1);
  res = lru->get(2);
  lru->put(3,3);
  lru->put(4,4);
  res = lru->get(1);
  res = lru->get(2);
  res = lru->get(4);
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */