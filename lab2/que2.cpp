//a*
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int g, h, f;
    bool operator<(const Node& other) const {
        return f > other.f; // min-heap
    }
};

void aStar(int start, int goal, vector<vector<pair<int,int>>> &graph, vector<int> &heuristic) {
    priority_queue<Node> pq;
    vector<int> g(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);

    g[start] = 0;
    pq.push({start, 0, heuristic[start], heuristic[start]});

    cout << "A* Path: ";
    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();
        if(visited[current.id]) continue;
        visited[current.id] = true;
        cout << current.id << " ";

        if(current.id == goal) {
            cout << "\nGoal reached with cost " << current.g << "\n";
            return;
        }

        for(auto &edge : graph[current.id]) {
            int neighbor = edge.first;
            int cost = edge.second;
            int tentative_g = current.g + cost;
            if(tentative_g < g[neighbor]) {
                g[neighbor] = tentative_g;
                int h = heuristic[neighbor];
                pq.push({neighbor, tentative_g, h, tentative_g + h});
            }
        }
    }
    cout << "\nGoal not reachable.\n";
}

int main() {
    int V = 6;
    vector<vector<pair<int,int>>> graph(V);
    vector<int> heuristic = {7,6,2,1,0,3};

    graph[0].push_back({1,2});
    graph[0].push_back({4,1});
    graph[1].push_back({2,2});
    graph[2].push_back({3,1});
    graph[4].push_back({5,3});

    aStar(0, 3, graph, heuristic);
    return 0;
}
