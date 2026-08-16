#include <stdbool.h>

/*@
    requires 2 <= n <= 100;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool func(int n) {
    //@ assert 2 <= n <= 100;
    return n % 2 == 0;
}

/*@
    requires 2 <= n <= 100;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool func2(int n) {
    bool is_even = true;
    
    //@ assert 2 <= n <= 100;
    
    if (n % 2 != 0) {
        is_even = false;
    }
    
    //@ assert is_even == (n % 2 == 0);
    return is_even;
}
