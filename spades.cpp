#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>

using namespace std;

//returns true if game is over and someone wins
bool update(int team1Score, int team2Score, string team1, string team2, int team1HandsMade, int team2HandsMade, int pointsToWin, int round){
    bool flag;
    if(team1Score >= pointsToWin){
        cout << "--------------------------------------" << endl;
        cout << team1 << " has won! Congrats!" << endl << endl;
        cout << "\tGame Overview:" << endl;
        flag = true;
    }
    else if(team2Score >= pointsToWin){
        cout << "--------------------------------------" << endl;
        cout << team2 << " has won! Congrats!" << endl << endl;
        cout << "\tGame Overview:" << endl;
        flag = true;
    }
    else{
        cout << "\tEnd Of Round Report:" << endl << endl;
        flag = false;
    }
    //normal end of round report
    cout << '\t' << team1 << "'s score: " << team1Score << endl;
    cout << '\t' << team1 << "'s hands made: " << team1HandsMade << endl;
    cout << '\t' << team1 << "'s hands busted: " << round - team1HandsMade << endl << endl;
    cout << '\t' << team2 << "'s score: " << team2Score << endl;
    cout << '\t' << team2 << "'s hands made: " << team2HandsMade << endl;
    cout << '\t' << team2 << "'s hands busted: " << round - team2HandsMade << endl << endl;
    return flag;
}

int main(int argc, char **argv) {

    //keep track of team names
    string team1;
    string team2;

    //how many points to win
    int pointsToWin;

    //get initialization information
    cout << "Welcome to Spades Tracker!" << endl;
    cout << "Team 1: ";
    getline(cin, team1);
    cout << endl;
    cout << "Team 2: ";
    getline(cin, team2);
    cout << endl;
    cout << "Points to win: ";
    cin >> pointsToWin;
    cout << endl;

    //keep track of the team scores
    int team1Score = 0;
    int team2Score = 0;

    //keeps track of how many hands each team called each round
    int team1HandsCalled = 0;
    int team2HandsCalled = 0;

    //keeps track of how many hands total each team made
    int team1HandsMade = 0;
    int team2HandsMade = 0;

    //varibles that track what round the game is on
    int roundCounter = 1;

    //true for when someone wins, false otherwise
    bool gameOver = false;

    //loops until game is over
    while(!gameOver){
        
        cout << "--------------------------------------" << endl;
        cout << "Round " << roundCounter << ":" << endl << endl;

        //gets hands called for team1
        cout << "How many hands does " << team1 << " call? ";
        cin >> team1HandsCalled;
        cout << endl;

        //gets hands called for team2
        cout << "How many hands does " << team2 << " call? ";
        cin >> team2HandsCalled;
        cout << endl << endl;

        //gets if team1 made their hands
        bool team1MadeHands;
        cout << "Did " << team1 << " make their hands? (1 for 'Yes', 0 for 'No') ";
        cin >> team1MadeHands;
        cout << endl;

        //gets if team2 made their hands
        bool team2MadeHands;
        cout << "Did " << team2 << " make their hands? (1 for 'Yes', 0 for 'No') ";
        cin >> team2MadeHands;
        cout << endl << endl;

        //updates scores for each team based on if they made their hands or not
        team1Score += (team1MadeHands ? 10 * team1HandsCalled : -10 * team1HandsCalled);
        team2Score += (team2MadeHands ? 10 * team2HandsCalled : -10 * team2HandsCalled);

        //updates the amount of hands teach team made 
        team1HandsMade += (team1MadeHands ? 1 : 0);
        team2HandsMade += (team2MadeHands ? 1 : 0);

        //checks to see if the game was won, if not, prints a post-round report
        gameOver = update(team1Score, team2Score, team1, team2, team1HandsMade, team2HandsMade, pointsToWin, roundCounter);

        //increments round
        roundCounter++;

    }

}