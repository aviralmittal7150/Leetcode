
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Greedily fit as many words as possible
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line or line containing a single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1)
                        line += ' ';
                }

                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                int totalSpaces = maxWidth - letters;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];

                    int spaces = spacesPerGap;
                    if (k - i < extraSpaces)
                        spaces++;

                    line += string(spaces, ' ');
                }

                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
