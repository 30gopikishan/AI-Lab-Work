//LAB 04: Implement Basic Search Strategies for Solving the 8-Puzzle, 8-Queens, and Tic-Tac-Toe Problems
//8puzzle(BFS Search)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int x, y; // blank position
    vector<string> path;
};

bool isGoal(vector<vector<int>> &state) {
    vector<vector<int>> goal = {{1,2,3},{4,5,6},{7,8,0}};
    return state == goal;
}

vector<Node> getNeighbors(Node current) {
    vector<Node> neighbors;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    string moves[] = {"Down","Up","Right","Left"};

    for(int i=0;i<4;i++) {
        int nx = current.x + dx[i];
        int ny = current.y + dy[i];
        if(nx>=0 && nx<3 && ny>=0 && ny<3) {
            Node next = current;
            swap(next.state[current.x][current.y], next.state[nx][ny]);
            next.x = nx; next.y = ny;
            next.path.push_back(moves[i]);
            neighbors.push_back(next);
        }
    }
    return neighbors;
}

void bfsPuzzle(vector<vector<int>> start) {
    queue<Node> q;
    set<vector<vector<int>>> visited;

    Node root;
    root.state = start;
    root.path = {};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(start[i][j]==0) { root.x=i; root.y=j; }

    q.push(root);
    visited.insert(root.state);

    while(!q.empty()) {
        Node current = q.front(); q.pop();
        if(isGoal(current.state)) {
            cout << "Solution found with moves: ";
            for(auto &m: current.path) cout << m << " ";
            cout << endl;
            return;
        }
        for(auto &neighbor: getNeighbors(current)) {
            if(!visited.count(neighbor.state)) {
                visited.insert(neighbor.state);
                q.push(neighbor);
            }
        }
    }
    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start = {{1,2,3},{4,0,6},{7,5,8}};
    bfsPuzzle(start);
    return 0;
}
