class Solution {
public:


    bool isFreqSame(int freq1[],int freq2[]){
        for(int i = 0;i < 26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i = 0;i < s1.size();i++){
            freq[s1[i] - 'a']++;
        }

        int windoSize = s1.size();


        for(int i = 0;i < s2.size();i++){
            int indx = i, windoIdx = 0;
            int windoFreq[26] = {0};

            while(windoIdx < windoSize && indx < s2.size()){
                windoFreq[s2[indx] - 'a']++;
                indx ++; windoIdx ++;
            }
            

            if(isFreqSame(freq,windoFreq)){
                return true;
            }
  
        }

        return false;
    }
};