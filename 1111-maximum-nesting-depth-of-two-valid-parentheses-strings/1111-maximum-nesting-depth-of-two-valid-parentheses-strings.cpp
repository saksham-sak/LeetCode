class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> arr;

        for(int i = 0;i < seq.size();i++){
            if(seq[i] == '('){
                arr.push_back(depth % 2);
                depth ++;
            }
            else if (seq[i] == ')'){
                depth --;
                arr.push_back(depth % 2);
            }
        }

        return arr;
    }
};