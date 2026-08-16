#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100) && (1 <= (t) <= 100);
    ensures \result == true <==> (s + t) % 2 == 0;
    ensures \result == false <==> (s + t) % 2 != 0;
    assigns \nothing;
*/
bool func(unsigned int s, unsigned int t) {
    bool is_even = false;
    unsigned int sum = s + t;
    
    /*@
        loop invariant 0 <= sum <= s + t;
        loop invariant (s + t - sum) % 2 == 0;
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= 2) {
        sum -= 2;
    }
    
    //@ assert sum == 0 || sum == 1;
    
    if (sum == 0) {
        is_even = true;
    }
    
    //@ assert is_even == true <==> (s + t) % 2 == 0;
    
    return is_even;
}
