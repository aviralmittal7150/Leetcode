
#include <bits/stdc++.h>
using namespace std;

class AllOne {
private:
    struct Bucket {
        int count;
        unordered_set<string> keys;

        Bucket(int c) : count(c) {}
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;

public:
    AllOne() {}

    void inc(string key) {
        auto it = keyToBucket.find(key);

        if (it == keyToBucket.end()) {
            // New key starts with count 1
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front(Bucket(1));
            }

            buckets.front().keys.insert(key);
            keyToBucket[key] = buckets.begin();
        } else {
            auto curr = it->second;
            auto next = std::next(curr);
            int newCount = curr->count + 1;

            // Create the next bucket if needed
            if (next == buckets.end() || next->count != newCount) {
                next = buckets.insert(next, Bucket(newCount));
            }

            next->keys.insert(key);
            keyToBucket[key] = next;

            curr->keys.erase(key);

            if (curr->keys.empty()) {
                buckets.erase(curr);
            }
        }
    }

    void dec(string key) {
        auto curr = keyToBucket[key];

        if (curr->count == 1) {
            keyToBucket.erase(key);
            curr->keys.erase(key);

            if (curr->keys.empty()) {
                buckets.erase(curr);
            }
            return;
        }

        int newCount = curr->count - 1;

        if (curr == buckets.begin() ||
            std::prev(curr)->count != newCount) {
            curr = buckets.insert(curr, Bucket(newCount));
        } else {
            curr = std::prev(curr);
        }

        curr->keys.insert(key);
        keyToBucket[key] = curr;

        auto old = std::next(curr);
        old->keys.erase(key);

        if (old->keys.empty()) {
            buckets.erase(old);
        }
    }

    string getMaxKey() {
        if (buckets.empty()) {
            return "";
        }

        return *buckets.back().keys.begin();
    }

    string getMinKey() {
        if (buckets.empty()) {
            return "";
        }

        return *buckets.front().keys.begin();
    }
};
