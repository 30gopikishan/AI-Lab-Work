//bfs
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int heuristic;
    bool operator<(const Node& other) const {
        return heuristic > other.heuristic; // min-heap behavior
    }
};

void bestFirstSearch(int start, int goal, vector<vector<pair<int,int>>> &graph, vector<int> &heuristic) {
    priority_queue<Node> pq;
    vector<bool> visited(graph.size(), false);

    pq.push({start, heuristic[start]});

    cout << "Best First Search Path: ";
    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();
        if(visited[current.id]) continue;
        visited[current.id] = true;
        cout << current.id << " ";

        if(current.id == goal) {
            cout << "\nGoal reached!\n";
            return;
        }

        for(auto &edge : graph[current.id]) {
            int neighbor = edge.first;
            if(!visited[neighbor]) {
                pq.push({neighbor, heuristic[neighbor]});
            }
        }
    }
    cout << "\nGoal not reachable.\n";
}

int main() {
    int V = 6;
    vector<vector<pair<int,int>>> graph(V);
    vector<int> heuristic = {7,6,2,1,0,3}; // example heuristic values

    // Graph edges (undirected for simplicity)
    graph[0].push_back({1,1});
    graph[0].push_back({4,1});
    graph[1].push_back({2,1});
    graph[2].push_back({3,1});
    graph[4].push_back({5,1});

    bestFirstSearch(0, 3, graph, heuristic);
    return 0;
}
