class Solution {
public:
    bool result(vector<int> &arr,int m,int target){
        int start = 0;
        int end = m - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return false;
    };
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        
        int start = 0;
        int end = matrix.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(target >= matrix[mid][0] && target <= matrix[mid][m - 1]){
                return result(matrix[mid],m,target);
            }

            else if(target < matrix[mid][0]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};