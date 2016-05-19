class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();
        if (s_size < t_size) {
            return 0;
        }
        int match[t_size];
        match[0] = 1;
        for (int i = 1; i <= t_size; i++) {
            match[i] = 0;
        }
        // s is the original string, t is the substring.
        for (int i = 1; i <= s_size; i++) {
            for (int j = t_size; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    match[j] += match[j - 1];
                }
            }
        }
        return match[t_size];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();
        if (s_size < t_size) {
            return 0;
        }
        int match[s_size + 1][t_size + 1];
        match[0][0] = 1;
        // s is empty
        for (int j = 1; j <= t_size; ++j) {
            match[0][j] = 0;
        }
        // t is empty
        for (int i = 1; i <= s_size; i++) {
            match[i][0] = 1;
        }
        for (int i = 1; i <= s_size; i++) {
            for (int j = 1; j <= t_size; j++) {
                match[i][j] = match[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    match[i][j] += match[i - 1][j - 1];
                }
            }
        }
        return match[s_size][t_size];
    }
};