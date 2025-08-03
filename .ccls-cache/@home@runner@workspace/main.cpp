#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void getTeams(const string &filename, vector<string> &teams);
int findWinner(const string &team, const vector<string> &winners);

int main() {
    vector<string> teams;
    vector<string> winners;

    // Load teams and winners from files
    getTeams("Teams.txt", teams);
    getTeams("WorldSeriesWinners.txt", winners);

    // Display all teams
    cout << "Teams that have won the World Series:\n";
    for (const string &team : teams) {
        cout << team << endl;
    }

    string input;
    cout << "\nEnter a team name to see how many times they have won (or type 'quit' to exit): ";
    getline(cin, input);

    while (input != "quit") {
        int count = findWinner(input, winners);
        if (count == 0)
            cout << input << " has not won the World Series in this period.\n";
        else
            cout << input << " has won the World Series " << count << " times.\n";

        cout << "\nEnter another team name (or 'quit' to exit): ";
        getline(cin, input);
    }

    cout << "\nThank you for using the program!\n";
    return 0;
}

void getTeams(const string &filename, vector<string> &teams) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Could not open " << filename << endl;
        exit(1);
    }

    string name;
    while (getline(inFile, name)) {
        if (!name.empty()) {
            teams.push_back(name);
        }
    }

    inFile.close();
}

int findWinner(const string &team, const vector<string> &winners) {
    int count = 0;
    for (const string &winner : winners) {
        if (winner == team) {
            count++;
        }
    }
    return count;
}
