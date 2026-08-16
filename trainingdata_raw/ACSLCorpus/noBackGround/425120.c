#include <stdbool.h>

/*@
    requires 2 <= n <= 100;
    requires 1 <= a < b <= n;
    ensures \result == ((a + b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a, unsigned int b) {
    unsigned int sum;
    bool is_even;
    
    sum = a + b;
    
    //@ assert sum == a + b;
    
    if (sum % 2 == 0) {
        is_even = true;
    } else {
        is_even = false;
    }
    
    //@ assert is_even == ((a + b) % 2 == 0);
    
    return is_even;
}
