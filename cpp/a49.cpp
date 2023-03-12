#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// State Beam[i][k]
// i: number of iteration
// k: k-th top score

struct State {
    int score;
    int X[29]; // current array
    char lastmove; // A or B
    int lastpos; // position State[i-1][??]
};


bool operator>(const State& a1, const State& a2) {
    if (a1.score > a2.score) return true;
    else return false;
};


int T;
int P[109], R[109], Q[109];
const int WIDTH = 10000;
const int N = 20;
int NumState[109];
State Beam[109][WIDTH];
char Answer[109];


void BeamSearch() {
    NumState[0] = 1;
    Beam[0][0].score = 0;
    for (int i = 1; i <= N; i++) Beam[0][0].X[i] = 0;

    for (int i = 1; i <= T; i++) {
        vector<State> Candidate;
        for (int j = 0; j < NumState[i-1]; j++) {
            // Case A
            State sousaA = Beam[i-1][j];
            sousaA.lastmove = 'A';
            sousaA.lastpos = j;
            sousaA.X[P[i]] += 1;
            sousaA.X[Q[i]] += 1;
            sousaA.X[R[i]] += 1;
            for (int k = 1; k <= N; k++) {
                if (sousaA.X[k] == 0) {
                    if (sousaA.X[k] == 0) sousaA.score += 1;
                } 
            }

            State sousaB = Beam[i-1][j];
            sousaB.lastmove = 'B';
            sousaB.lastpos = j;
            sousaB.X[P[i]] -= 1;
            sousaB.X[Q[i]] -= 1;
            sousaB.X[R[i]] -= 1;
            for (int k = 1; k <= N; k++) {
                if (sousaB.X[k] == 0) {
                    if (sousaB.X[k] == 0) sousaB.score += 1;
                } 
            }

            Candidate.push_back(sousaA);
            Candidate.push_back(sousaB);

        }
        sort(Candidate.begin(), Candidate.end(), greater<State>());
        NumState[i] = min(WIDTH, (int)Candidate.size());
        for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidate[j];

    }
    
}


int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> P[i] >> Q[i] >> R[i];
    };

    BeamSearch();

    int currentpos = 0;
    for (int i = T; i >= 1; i--) {
        Answer[i] = Beam[i][currentpos].lastmove;
        currentpos = Beam[i][currentpos].lastpos;
    }

    for (int i = 1; i <= T; i++) cout << Answer[i] << endl;
    return 0;
}

