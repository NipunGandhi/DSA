class Solution{
public:
	int search(string pat, string txt) {
        vector<int> charCount(26, 0); 

        int ans = 0;
        int k = pat.size();
        int i = 0, j = 0;

        for (char c : pat) {
            charCount[c - 'a']++; 
        }

        int count = 0; 

        for (int i = 0; i < 26; i++) {
            if (charCount[i] > 0) {
                count++;
            } else {
                charCount[i] = INT_MIN;
            }
        }
        
        while (j < txt.size()) {
            char currentChar = txt[j];

            if (charCount[currentChar - 'a'] != INT_MIN) {
                charCount[currentChar - 'a']--;

                if (charCount[currentChar - 'a'] == 0) {
                    count--;
                }
            }

            if (j - i + 1 == k) {
                if (count == 0) {
                    ans += 1;
                }

                if (charCount[txt[i] - 'a'] != INT_MIN) {
                    charCount[txt[i] - 'a']++;

                    if (charCount[txt[i] - 'a'] == 1) {
                        count++;
                    }
                }

                i++;
            }

            j++;
        }

        return ans;
    }

};