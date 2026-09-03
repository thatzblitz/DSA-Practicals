#include <iostream>
#include <vector>

using namespace std;

// Depth First Search (DFS) Traversal for a Graph
// Time Complexity: O(V + E) where V is vertices and E is edges
// Space Complexity: O(V) for the recursion call stack and visited array

void dfs(int current, const vector<vector<int>> &adj, vector<bool> &visited) {
  // Step 1: Mark the current node as visited and process (print) it
  visited[current] = true;
  cout << current << " ";

  // Step 2: Recursively visit all unvisited adjacent vertices
  for (int neighbor : adj[current]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adj, visited);
    }
  }
}

int main() {
  int V, E;
  cout << "=== Depth First Search (DFS) in C++ ===\n";
  cout << "Enter number of vertices: ";
  cin >> V;

  cout << "Enter number of edges: ";
  cin >> E;

  // Adjacency list representation of graph
  vector<vector<int>> adj(V);

  cout << "Enter " << E << " edges (u v) [0-indexed, e.g., 0 1]:\n";
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;

    // Since it is an undirected graph, add edge both ways
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int startNode;
  cout << "Enter starting vertex for DFS (0 to " << V - 1 << "): ";
  cin >> startNode;

  // Array to keep track of visited vertices
  vector<bool> visited(V, false);

  cout << "\nDFS Traversal starting from vertex " << startNode << ": ";
  dfs(startNode, adj, visited);
  cout << endl;

  return 0;
}
