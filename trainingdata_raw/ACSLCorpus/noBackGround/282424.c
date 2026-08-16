#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100 && 1 <= (y) <= 100);
    ensures \result == true <==> (x * y) % 2 == 0;
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    unsigned int product;
    bool is_even;
    unsigned int temp;

    //@ assert (1 <= (x) <= 100 && 1 <= (y) <= 100);
    
    product = x * y;
    
    // Manual modulo implementation
    temp = product;
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant (1 <= (x) <= 100 && 1 <= (y) <= 100);
        loop invariant product == x * y;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    is_even = (temp == 0);
    
    //@ assert is_even == ((x * y) % 2 == 0);
    
    return is_even;
}
