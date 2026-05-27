class Solution {
public:

    vector<int> bfs(int src,int n,vector<vector<int>>& adj){

        queue<int> q;
        vector<int> dist(n,-1);

        q.push(src);
        dist[src]=0;

        while(!q.empty()){

            int u=q.front();
            q.pop();

            for(int v:adj[u]){

                if(dist[v]==-1){

                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }

        return dist;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n=wordList.size();

        vector<vector<int>> adj(n+1);

        // build graph
        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int ct=0;

                for(int k=0;k<wordList[i].size();k++){

                    if(wordList[i][k]!=wordList[j][k])
                        ct++;
                }

                if(ct==1){

                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int idx=-1;
        int dest=-1;

        for(int i=0;i<n;i++){

            if(wordList[i]==endWord)
                dest=i;

            if(wordList[i]==beginWord)
                idx=i;
        }

        // endWord absent
        if(dest==-1)
            return 0;

        // if beginWord not in list
        if(idx==-1){

            for(int i=0;i<n;i++){

                int ct=0;

                for(int k=0;k<beginWord.size();k++){

                    if(beginWord[k]!=wordList[i][k])
                        ct++;
                }

                if(ct==1){

                    adj[n].push_back(i);
                    adj[i].push_back(n);
                }
            }

            idx=n;
        }

        vector<int> dist=bfs(idx,n+1,adj);

        if(dist[dest]==-1)
            return 0;

        return dist[dest]+1;
    }
};