//hill climbing
#include <bits/stdc++.h>
using namespace std;

int heuristic(int x) {
    return -(x-3)*(x-3) + 9; // peak at x=3
}

void hillClimbing(int start) {
    int current = start;
    cout << "Hill Climbing Path: ";
    while(true) {
        cout << current << " ";
        int left = current - 1;
        int right = current + 1;
        int best = current;

        if(heuristic(left) > heuristic(best)) best = left;
        if(heuristic(right) > heuristic(best)) best = right;

        if(best == current) {
            cout << "\nReached local maximum at " << current << " with value " << heuristic(current) << "\n";
            break;
        }
        current = best;
    }
}

int main() {
    hillClimbing(0);
    return 0;
}
