#include <stdbool.h>

/*@
    requires (0 <= (x) <= 10000 && 0 <= (y) <= 10000);
    ensures \result == (((x) * (y)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;
    unsigned int temp;

    //@ assert (0 <= (x) <= 10000 && 0 <= (y) <= 10000);
    
    // Ensure no overflow in x * y
    //@ assert ((x) * (y)) <= 100000000;
    
    product = x * y;
    
    // Implementing the modulus operation manually
    temp = product;
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    is_even = (temp == 0);
    
    //@ assert is_even == (((x) * (y)) % 2 == 0);
    
    return is_even;
}
