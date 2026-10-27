class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        res.emplace_back(n, '.');
        for(int i = 1; i < m; i++) {
            res.emplace_back(n-1, '#');
            res.back() += '.';
        }

        return res;
    }
};