#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    bool is_even;
    unsigned int result;
    unsigned int temp;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    result = a * b;
    
    //@ assert 1 <= result <= 10000 * 10000;
    
    is_even = true;
    temp = result;

    /*@
        loop invariant 0 <= temp <= result;
        loop invariant temp % 2 == result % 2;
        loop invariant (result % 2 == 0) ==> is_even == \true;
        loop assigns temp, is_even;
        loop variant temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }

    if (temp == 1) {
        is_even = false;
    }

    //@ assert is_even == (result % 2 == 0);
    
    return is_even;
}
