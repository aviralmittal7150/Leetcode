class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        dict.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (dict.count(word)) {
                        q.push({word, steps + 1});
                        dict.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};