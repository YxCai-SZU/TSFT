#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result <==> ((n) % 10 == 9);
    assigns \nothing;
*/
bool func(int n) {
    unsigned int n_unsigned;
    unsigned int last_digit;
    unsigned int tmp;
    
    n_unsigned = (unsigned int)n;
    last_digit = n_unsigned % 10;
    
    //@ assert last_digit == n_unsigned % 10;
    
    if (last_digit == 9) {
        tmp = 9;
    } else {
        tmp = last_digit;
    }
    
    //@ assert tmp == 9 <==> n_unsigned % 10 == 9;
    
    return tmp == 9;
}
