#include <bits/stdc++.h>
using namespace std;

// Rule structure
struct Rule {
    vector<string> premises;
    string conclusion;
};

// Forward Chaining
void forwardChaining(vector<Rule> &rules, set<string> facts, string goal) {
    cout << "Forward Chaining:\n";
    bool added = true;
    while(added) {
        added = false;
        for(auto &rule : rules) {
            bool satisfied = true;
            for(auto &premise : rule.premises) {
                if(facts.find(premise) == facts.end()) {
                    satisfied = false;
                    break;
                }
            }
            if(satisfied && facts.find(rule.conclusion) == facts.end()) {
                facts.insert(rule.conclusion);
                cout << "Derived: " << rule.conclusion << endl;
                added = true;
                if(rule.conclusion == goal) {
                    cout << "Goal " << goal << " reached!\n";
                    return;
                }
            }
        }
    }
    cout << "Goal " << goal << " not reached.\n";
}

// Backward Chaining
bool backwardChaining(vector<Rule> &rules, set<string> facts, string goal) {
    if(facts.find(goal) != facts.end()) {
        cout << "Fact " << goal << " is known.\n";
        return true;
    }
    for(auto &rule : rules) {
        if(rule.conclusion == goal) {
            cout << "To prove " << goal << ", check premises: ";
            for(auto &p : rule.premises) cout << p << " ";
            cout << endl;
            bool allTrue = true;
            for(auto &premise : rule.premises) {
                if(!backwardChaining(rules, facts, premise)) {
                    allTrue = false;
                    break;
                }
            }
            if(allTrue) {
                cout << "Therefore, " << goal << " is true.\n";
                return true;
            }
        }
    }
    cout << "Cannot prove " << goal << ".\n";
    return false;
}

int main() {
    // Define rules
    vector<Rule> rules = {
        {{"A","B"}, "C"},
        {{"C"}, "D"},
        {{"D"}, "E"}
    };

    // Facts
    set<string> facts = {"A","B"};

    // Forward Chaining Example
    forwardChaining(rules, facts, "D");

    cout << "\nBackward Chaining:\n";
    // Backward Chaining Example
    backwardChaining(rules, facts, "E");

    return 0;
}
