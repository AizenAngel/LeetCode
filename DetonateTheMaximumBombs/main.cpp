
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool willDetonateEachOther(vector<int> PointA, vector<int> PointB) {
  ll dist = ll(PointA[0] - PointB[0]) * ll(PointA[0] - PointB[0]) + ll(PointA[1] - PointB[1]) * ll(PointA[1] - PointB[1]);
  ll square = PointA[2] * PointA[2];

  return dist <= square;
}

vector<vector<int>> makeGraph(vector<vector<int>> bombs) {
  vector<vector<int>> graph(bombs.size());

  for(int i = 0; i < bombs.size(); i++) {
    for(int j = 0; j < bombs.size(); j++) {
      if (willDetonateEachOther(bombs[i], bombs[j])) {
        graph[i].push_back(j);
      }
    }
  }

  return graph;
}

int detonateFromPoint(vector<vector<int>>& bombs, vector<bool>& visited, int node) {
  visited[node] = true;
  int val = 1;

  for(int i = 0; i < bombs[node].size(); i++) {
    if(!visited[bombs[node][i]]) {
      val += detonateFromPoint(bombs, visited, bombs[node][i]);
    }
  }

  return val;
}

int maximumDetonation(vector<vector<int>>& bombs) {
  vector<vector<int>> graph = makeGraph(bombs);
  int currMax = 1;

  for(int i = 0; i < bombs.size(); i++) {
    vector<bool> visited(bombs.size());
    int newMax = detonateFromPoint(graph, visited, i);
    currMax = newMax > currMax ? newMax : currMax;
  }

  return currMax;
}

int main(int argc, char** argv) {
  vector<vector<int>> bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
  // vector<vector<int>> graph = makeGraph(bombs);

  // for(int i = 0; i < graph.size(); i++) {
  //   for(int j = 0; j < graph[i].size(); j++) {
  //     cout<<graph[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }

  cout<<maximumDetonation(bombs)<<"\n";

  return 0;
}

// 69, 51, 7
// 65, 59, 3