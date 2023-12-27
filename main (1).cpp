#include "finite-state machine.h"
using namespace std;

int main() {
    // Example of a finite state machine that checks for the occurrence of substrings 1, 2, 3
    int states1 = 4;
    vector<int> alphabetInt = {1, 2, 3};
    int initialState1 = 0;
    int finalState1 = 3;
    vector<vector<int>> transitions1 = {{1, 0, 0}, {1, 2, 0}, {1, 0, 3}, {3, 3, 3}};
    FiniteStateMachine<int> fsmInt(states1, alphabetInt, initialState1, finalState1, transitions1);

    vector<int> inputListInt = {1, 2, 2, 2, 2, 1, 1};
    cout << "Result for FSM with integers: " << fsmInt.check_str(inputListInt) << endl;

    // Example of a finite state machine that checks for the occurrence of either 'abd' or 'cbc'
    int states2 = 6;
    vector<char> alphabetChar = {'a', 'b', 'c', 'd'};
    int initialState2 = 0;
    int finalState2 = 5;
    vector<vector<int>> transitions2 = {{1, 0, 3, 0}, {1, 2, 3, 0}, {1, 0, 3, 5},
                                        {1, 4, 3, 0}, {1, 0, 5, 0}, {5, 5, 5, 5}};
    vector<char> inputListChar = {'a', 'b', 'c', 'b', 'c', 'b', 'b', 'b'};
    FiniteStateMachine<char> fsmChar(states2, alphabetChar, initialState2, finalState2, transitions2);
    cout << "Result for FSM with characters: " << fsmChar.check_str(inputListChar) << endl;

    return 0;
}
