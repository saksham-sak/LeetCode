class Solution {
public:
    typedef pair<int,int> P;
    typedef tuple<long,int,int> T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> result(m);

        priority_queue<P,vector<P>,greater<P>> freeServer;
        
        for(int i = 0;i < n;i++){
            freeServer.push({servers[i],i});
        }

        priority_queue<T,vector<T>,greater<T>> busyServer;

        for(int i = 0;i < m;i++){
            while(!busyServer.empty() && get<0>(busyServer.top()) <= i){
                auto [finTime,wt,idx] = busyServer.top();
                busyServer.pop();
                freeServer.push({wt,idx});
            }

            if(freeServer.empty()){
                auto [finTime,wt,idx] = busyServer.top();
                busyServer.pop();
                result[i] = idx;
                busyServer.push({finTime + tasks[i],wt,idx});
            }else{
                auto [wt,idx] = freeServer.top();
                freeServer.pop();
                result[i] = idx;
                busyServer.push({i + tasks[i],wt,idx});
            }
        }

        return result;
        
    }
};