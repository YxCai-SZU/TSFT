#include <stdbool.h>

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    ensures \result == ((a < c && b > c) || (a > c && b < c));
    assigns \nothing;
*/
bool can_reach_house_3_straight_c(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    result = (a < c && b > c) || (a > c && b < c);
    //@ assert result == ((a < c && b > c) || (a > c && b < c));
    return result;
}

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    ensures \result == (a != b && a != c && b != c);
    assigns \nothing;
*/
bool can_reach_house_3_turn_c(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    result = a != b && a != c && b != c;
    //@ assert result == (a != b && a != c && b != c);
    return result;
}

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    ensures \result <= 2;
    assigns \nothing;
*/
unsigned int count_turns_c(int a, int b, int c, int d) {
    unsigned int turns;
    turns = 0;
    
    if (a != b && a != c && b != c) {
        turns = turns + 1;
    }
    if (c != d && a != d && b != d) {
        turns = turns + 1;
    }
    //@ assert turns <= 2;
    return turns;
}

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    ensures \result <= 2;
    assigns \nothing;
*/
unsigned int func_c(int a, int b, int c, int d) {
    bool can_reach_3_straight;
    bool can_reach_3_turn;
    unsigned int total_turns;
    unsigned int result;
    
    can_reach_3_straight = can_reach_house_3_straight_c(a, b, c);
    can_reach_3_turn = can_reach_house_3_turn_c(a, b, c);
    total_turns = count_turns_c(a, b, c, d);
    
    if (can_reach_3_straight) {
        result = 1;
    } else if (can_reach_3_turn) {
        result = 2;
    } else {
        result = total_turns;
    }
    //@ assert result <= 2;
    return result;
}
