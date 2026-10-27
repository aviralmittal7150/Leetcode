class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> idx;
        for (int i = 0; i < list1.size(); i++) idx[list1[i]] = i;

        int best = INT_MAX;
        vector<string> result;

        for (int j = 0; j < list2.size(); j++) {
            auto it = idx.find(list2[j]);
            if (it != idx.end()) {
                int total = it->second + j;
                if (total < best) {
                    best = total;
                    result = {list2[j]};
                } else if (total == best) {
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};