class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        set<string> current;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++;  // skip '{'

                set<string> inside = parse(s, i);

                i++;  // skip '}'

                // Concatenate current × inside
                if (current.empty()) {
                    current = inside;
                } else {
                    set<string> temp;

                    for (string a : current) {
                        for (string b : inside) {
                            temp.insert(a + b);
                        }
                    }

                    current = temp;
                }
            }

            else if (s[i] == ',') {
                // Everything before comma belongs to union
                result.insert(current.begin(), current.end());
                current.clear();
                i++;
            }

            else {
                // Single letter
                set<string> letter;
                letter.insert(string(1, s[i]));

                if (current.empty()) {
                    current = letter;
                } else {
                    set<string> temp;

                    for (string a : current) {
                        for (string b : letter) {
                            temp.insert(a + b);
                        }
                    }

                    current = temp;
                }

                i++;
            }
        }

        // Add last part
        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};