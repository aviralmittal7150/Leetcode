class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
         priority_queue<int, vector<int>, greater<int>> freeQ;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for (int i = 0; i < k; i++) freeQ.push(i);

        vector<int> cnt(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int id = busy.top().second;
                busy.pop();
                freeQ.push(i + ((id - i) % k + k) % k);
            }
            if (freeQ.empty()) continue;

            int id = freeQ.top() % k;
            freeQ.pop();
            cnt[id]++;
            busy.push({(long long)arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) res.push_back(i);
        }
        return res;
    }
};