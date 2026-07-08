class Solution {
public:
    string frequencySort(string s) {
        vector<int>v(62);
        for(auto& x:s){
            if(x-'A'<0){
                v[x-'0'+52]++;
            }
            else if(x-'a'<0){
                v[x-'A']++;
            }
            else v[x-'a'+26]++;
        }
        vector<pair<int,char>>v1;
        for(int i=0;i<62;i++){
            if(v[i]>0 and i<26){
                v1.push_back({v[i],'A'+i});
            }
            else if(v[i]>0 and i<52){
                v1.push_back({v[i],'a'+(i-26)});
            }
            else if(v[i]>0){
                v1.push_back({v[i],'0'+(i-52)});
            }
        }
        sort(v1.rbegin(),v1.rend());
        string ans;
        for(auto& [f,c]:v1){
            for(int i=0;i<f;i++)ans.push_back(c);
        }
        return ans;


    }
};