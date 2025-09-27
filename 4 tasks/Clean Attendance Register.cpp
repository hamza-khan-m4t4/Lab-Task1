#include <iostream>
using namespace std;

int main() {
    int numParticipants;
    cout << "Enter number of participants: ";
    cin >> numParticipants;

    int *attendance = new int[numParticipants];

    for (int i = 0; i < numParticipants; i++) {
        *(attendance + i) = 0;
    }

    int presentCount;
    cout << "How many participants are present? ";
    cin >> presentCount;

    for (int i = 0; i < presentCount; i++) {
        int index;
        cout << "Enter participant number (1 to " << numParticipants << ") to mark present: ";
        cin >> index;
        if (index >= 1 && index <= numParticipants) {
            *(attendance + (index - 1)) = 1;
        } else {
            cout << "Invalid number. Skipping.\n";
        }
    }

    cout << "\n--- Final Attendance List ---\n";
    for (int i = 0; i < numParticipants; i++) {
        cout << "Participant " << i + 1 << ": " << (*(attendance + i) == 1 ? "Present" : "Absent") << endl;
    }

    delete[] attendance;
    attendance = nullptr;

    return 0;
}
