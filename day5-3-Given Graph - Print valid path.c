#include <bits/stdc++.h>
using namespace std;
void printPath(vector<char>& path) {
   int size = path.size();
   for (int i = 0; i < size; i++)
   cout<<path[i]<<" ";
   cout<<endl;
}
int isVertexVisited(char x, vector<char>& path) {
   int size = path.size();
   for (int i = 0; i< size; i++)
   if (path[i] == x)
   return 1;
   return 0;
}
void pathSourceToDestination(vector<vector<char> >&g, char src, char dst, int v) {
   queue<vector<char> > q;
   vector<char> path;
   path.push_back(src);
   q.push(path);
   while (!q.empty()) {
      path = q.front();
      q.pop();
      char last = path[path.size() - 1];
      if (last == dst)
      printPath(path);
      for (int i = 0; i < g[last].size(); i++) {
         if (!isVertexVisited(g[last][i], path)) {
            vector<char> newpath(path);
            newpath.push_back(g[last][i]);
            q.push(newpath);
         }
      }
   }
}
int main() {
   vector<vector<char> > g;
   int v = 4;
   g.resize(4);
   g['X'].push_back('S');
   g['X'].push_back('A');
   g['X'].push_back('N');
   g['A'].push_back('S');
   g['N'].push_back('X');
   g['N'].push_back('A');
   char src = 'N', dst = 'S';
   cout<<"path from src "<<src<<" to dst "<<dst<<" are \n";
   pathSourceToDestination(g, src, dst, v);
   return 0;
}
