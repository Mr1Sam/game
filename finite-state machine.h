#ifndef FINITE_STATE_MACHINE_H
#define FINITE_STATE_MACHINE_H


#include <string>
#include <vector>
#include <iostream>

template <class Type>
class FiniteStateMachine {
public:
    FiniteStateMachine(int states_, std::vector<Type> alphabet_, int state_, 
                       int final_state_, std::vector<std::vector<int>> transition_) {
        states = states_;
        alphabet = alphabet_;
        state = state_;
        final_state = final_state_;
        transition = transition_;
    }

    bool check_str(std::vector<Type> str) {
        Type str_now;
        int ind;

        for (int i = 0; i < str.size(); ++i) {
            str_now = str[i];
            ind = alphabet_ind(str_now);

            if (ind >= 0) {
                state = transition[state][ind];
            } else {
                return false;
            }
        }

        return state == final_state;
    }

private:
    int states;
    std::vector<Type> alphabet;
    int state;
    int final_state;
    std::vector<std::vector<int>> transition;

    int alphabet_ind(Type char_now) {
        for (int k = 0; k < alphabet.size(); ++k) {
            if (alphabet[k] == char_now) return k;
        }
        return -1;
    }
};

#endif // FINITE_STATE_MACHINE_H
