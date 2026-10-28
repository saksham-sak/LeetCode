class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> newheight = heights;
        sort(newheight.begin(),newheight.end());
        int count = 0;

        for(int i = 0;i < heights.size();i++){
            if(newheight[i] != heights[i]){
                count += 1;
            }
        }

        return count;
    }
};