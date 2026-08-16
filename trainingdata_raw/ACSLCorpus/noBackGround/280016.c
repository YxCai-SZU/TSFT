#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == (int)(a * b + 1) || \result == -1;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int max_val;
    bool is_prime;
    unsigned int i;
    unsigned int remainder;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    // Ensure no overflow in a * b
    //@ assert a * b <= 10000;
    
    max_val = a * b + 1;
    //@ assert ((max_val) == (a) * (b) + 1);
    
    if (max_val < 2) {
        return -1;
    }
    
    is_prime = true;
    i = 2;
    
    /*@
        loop invariant 2 <= i && i <= max_val;
        loop invariant ((max_val) == (a) * (b) + 1);
        loop invariant is_prime == true || is_prime == false;
        loop invariant (1 <= (a) && (a) <= 100);
        loop invariant (1 <= (b) && (b) <= 100);
        loop assigns i, is_prime, remainder;
        loop variant max_val - i;
    */
    while (i < max_val) {
        remainder = max_val;
        
        /*@
            loop invariant remainder >= 0;
            loop invariant remainder <= max_val;
            loop invariant ((max_val) == (a) * (b) + 1);
            loop invariant (1 <= (a) && (a) <= 100);
            loop invariant (1 <= (b) && (b) <= 100);
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= i) {
            remainder -= i;
        }
        
        if (remainder == 0) {
            is_prime = false;
            break;
        }
        
        i += 1;
    }
    
    if (is_prime) {
        //@ assert max_val == a * b + 1;
        return (int)max_val;
    } else {
        return -1;
    }
}
