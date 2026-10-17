class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector <vector<int>> newarr;
        int currentFirst = intervals[0][0];
        int currentLast = intervals[0][1];
        

        for(int i = 1;i < intervals.size();i++){
            if(currentLast >= intervals[i][0]){
                currentLast = max(intervals[i][1],currentLast);
            }
            else{
                newarr.push_back({currentFirst,currentLast});
                currentLast = intervals[i][1];
                currentFirst = intervals[i][0];
            }
        }
        newarr.push_back({currentFirst,currentLast});
        return newarr;
    }
};