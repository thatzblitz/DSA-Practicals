#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Breadth First Search (BFS) Traversal for a Graph
// Time Complexity: O(V + E) where V is vertices and E is edges
// Space Complexity: O(V) for the queue and visited array

void bfs(int startNode, const vector<vector<int>> &adj, int totalVertices) {
  // Array to keep track of visited vertices so we don't visit a node twice
  vector<bool> visited(totalVertices, false);

  // Queue for BFS (FIFO: First In First Out)
  queue<int> q;

  // Step 1: Mark the starting node as visited and push it into the queue
  visited[startNode] = true;
  q.push(startNode);

  cout << "\nBFS Traversal starting from vertex " << startNode << ": ";

  // Step 2: Loop until queue becomes empty
  while (!q.empty()) {
    // Pop the front element
    int current = q.front();
    q.pop();
    cout << current << " ";

    // Step 3: Visit all unvisited neighbors of current node
    for (int neighbor : adj[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true; // mark visited immediately when pushing
        q.push(neighbor);
      }
    }
  }
  cout << endl;
}

int main() {
  int V, E;
  cout << "=== Breadth First Search (BFS) in C++ ===\n";
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
  cout << "Enter starting vertex for BFS (0 to " << V - 1 << "): ";
  cin >> startNode;

  // Perform BFS
  bfs(startNode, adj, V);

  return 0;
}
