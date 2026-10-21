class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Case 1: Already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // An unsorted string of length 2 cannot be changed
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Case 2: One operation is enough
        if (s.front() == mn || s.back() == mx) {
            return 1;
        }

        // Case 3: Two operations are enough
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == mn) {
                return 2;
            }
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == mx) {
                return 2;
            }
        }

        // Case 4: Three operations are needed
        return 3;
    }
};
