#include <iostream>
using namespace std;

int main() {
    int numPlayers;
    cout << "Enter number of players: ";
    cin >> numPlayers;

    int *scores = new int[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter score for player " << i + 1 << ": ";
        cin >> *(scores + i);
    }

    cout << "\n--- Player Scores ---\n";
    for (int i = 0; i < numPlayers; i++) {
        cout << "Player " << i + 1 << ": " << *(scores + i) << endl;
    }

    delete[] scores;
    scores = nullptr;

    return 0;
}
