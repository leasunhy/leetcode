// Date: 2016-03-16

#include <list>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) : capacity(capacity), indicies(capacity) {}
    
    int get(int key) {
        auto iter = indicies.find(key);
        if (iter == indicies.end())
            return -1;
        data.push_front(*iter->second);
        data.erase(iter->second);
        iter->second = data.begin();
        return iter->second->second;
    }
    
    void set(int key, int value) {
        auto iter = indicies.find(key);
        if (iter != indicies.end()) {
            data.erase(iter->second);
        } else if (data.size() >= capacity) {
            // remove
            indicies.erase(data.rbegin()->first);
            data.pop_back();
        }
        data.emplace_front(key, value);
        indicies[key] = data.begin();
    }

private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> indicies;
    list<pair<int, int>> data;
};
