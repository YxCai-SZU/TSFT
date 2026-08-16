#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b) {
    // Variable declarations at scope top
    unsigned long product;
    bool is_even;
    unsigned long temp;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    product = a * b;
    is_even = false;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant (product - temp) % 2 == 0;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }
    
    if (temp == 0) {
        is_even = true;
    }
    
    return is_even;
}
