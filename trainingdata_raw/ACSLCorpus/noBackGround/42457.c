#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool result = false;
    unsigned int temp;
    
    //@ assert a * b <= 100000000;
    
    product = a * b;
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
    
    if (temp == 1)
    {
        result = true;
    }
    
    //@ assert result == (product % 2 != 0);
    return result;
}
