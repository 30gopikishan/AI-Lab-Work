//ao*
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    vector<vector<Node*>> children; // OR groups of AND children
};

void AOStar(Node* node) {
    if(node->children.empty()) {
        cout << node->name << " ";
        return;
    }
    cout << node->name << " -> ";
    // Choose first OR option for simplicity
    vector<Node*> bestOption = node->children[0];
    for(Node* child : bestOption) {
        AOStar(child);
    }
}

int main() {
    Node A{"A"}, B{"B"}, C{"C"}, D{"D"}, E{"E"};
    A.children.push_back({&B, &C}); // AND relation
    B.children.push_back({&D});     // OR relation
    C.children.push_back({&E});     // OR relation

    cout << "AO* Path: ";
    AOStar(&A);
    cout << "\n";
    return 0;
}
