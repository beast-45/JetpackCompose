class Solution {
    public:
      void graphDFS(unordered_map<int,vector<int>> &adj , int u , vector<bool> &visited , vector<int> &result){
          if(visited[u] == true){
              return;
          }
          visited[u] = true;
          result.push_back(u);
          for(int &v : adj[u]){
              if(!visited[v]){
                  graphDFS(adj , v , visited , result);
              }
          }
          
      }
      vector<int> dfsOfGraph(vector<vector<int>>& mp) {
          int V = mp.size();
          unordered_map<int,vector<int>> adj;
          for(int u=0 ; u<V ; u++){
              for(auto v = mp[u].begin() ; v != mp[u].end() ; v++){
                  adj[u].push_back(*v);
              }
          }
          vector<int> result;
          vector<bool> visited(V,false);
          
          graphDFS(adj , 0 , visited , result);
          
          return result;
      }
  };