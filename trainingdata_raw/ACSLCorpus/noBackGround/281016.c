#include <stdbool.h>

/*@
    requires 2 <= k <= 100;
    ensures \result == (k / 2) * 2 + (k % 2) * 3;
    assigns \nothing;
*/
int func(int k) {
    int result;
    bool is_even;
    int temp_k;
    int quotient;
    
    result = 0;
    is_even = true;
    temp_k = k;
    quotient = 0;
    
    /*@
        loop invariant 0 <= quotient <= k/2;
        loop invariant 0 <= temp_k <= k;
        loop invariant temp_k == k - 2 * quotient;
        loop invariant temp_k % 2 == k % 2;
        loop assigns temp_k, quotient;
    */
    while (temp_k >= 2) {
        //@ assert 2 * quotient <= k - 2;
        temp_k -= 2;
        quotient += 1;
    }
    
    result = quotient * 2;
    
    if (temp_k == 1) {
        is_even = false;
    }
    
    if (!is_even) {
        result += 3;
    }
    
    //@ assert result == (k / 2) * 2 + (k % 2) * 3;
    return result;
}
