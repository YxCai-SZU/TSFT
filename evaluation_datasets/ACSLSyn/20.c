#include <stdbool.h>

/*@ predicate sum_ge_22(integer a, integer b, integer c) = a + b + c >= 22; */

/*@ predicate is_valid_params(integer k, integer x) =
        1 <= k <= 100 &&
        1 <= x <= 100000;
*/

/*@ logic integer threshold(integer k) = k * 500; */

/*@ lemma threshold_positive: 
        \forall integer k; 1 <= k <= 100 ==> threshold(k) > 0;
*/

bool func1(int A[3]) {
    int a0, a1, a2;
    bool result;
    
    a0 = A[0];
    a1 = A[1];
    a2 = A[2];
    
    if (a0 + a1 + a2 >= 22) {
        result = true;
        //@ assert sum_ge_22(a0, a1, a2);
    } else {
        //@ assert !sum_ge_22(a0, a1, a2);
        result = false;
    }
    
    return result;
}

bool func2(unsigned int k, unsigned int x) {
    bool result;
    
    result = (k * 500 >= x);
    return result;
}


bool blackjack_bet_validator(int A[3], unsigned int k, unsigned int x) {
    bool hand_strong = func1(A);
    bool bet_affordable = func2(k, x);
    bool result;
    
    if (hand_strong && bet_affordable) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true ==> (sum_ge_22(A[0], A[1], A[2]) && threshold(k) >= x);
    
    return result;
}
