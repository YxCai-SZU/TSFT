#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;
    unsigned int temp;
    
    //@ assert a <= 10000 && b <= 10000;
    
    //@ assert ((a) * (b)) <= 100000000;
    
    product = a * b;
    
    is_even = false;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
        loop invariant ((a) * (b)) <= 100000000;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    if (temp == 0)
    {
        is_even = true;
    }
    else
    {
        is_even = false;
    }
    
    return is_even;
}
