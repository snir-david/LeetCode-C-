//
// Created by SnirN on 1/28/2025.
//

#ifndef LEETCODE_150_C___MAPSUM_HPP
#define LEETCODE_150_C___MAPSUM_HPP
#include <string>
#include <unordered_map>

class MapSum {
public:
  MapSum() {

  }

  void handleAllPrefixes(std::string &key, int val){
    for(size_t idx = 1; idx <= key.size(); ++idx){
      auto prefix = key.substr(0, idx);
      auto it = prefixMap.find(prefix);
      if(it != prefixMap.end()){
        it->second += val;
      }
      else
      {
        prefixMap.insert({prefix, val});
      }
    }
  }

  void insert(std::string key, int val) {
    int newVal = val;
    auto it = KeysMap.find(key);
    if(it != KeysMap.end()){
      newVal -= it->second;
      it->second = val;
    }
    else
    {
      KeysMap.insert({key, val});
    }
    handleAllPrefixes(key, newVal);
  }

  int sum(std::string prefix) {
    auto it1 = prefixMap.find(prefix);
    int res = 0;
    if(it1 != prefixMap.end())
    {
      res += it1->second;
    }
    return res;
  }

  std::unordered_map<std::string, int> prefixMap;
  std::unordered_map<std::string, int> KeysMap;
};

void testMapSum(){
  MapSum* obj = new MapSum();
  obj->insert("apple",3);
  int res = obj->sum("ap");
  obj->insert("app",2);
  obj->insert("apple",2);
  res = obj->sum("ap");
}
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
#endif // LEETCODE_150_C___MAPSUM_HPP
