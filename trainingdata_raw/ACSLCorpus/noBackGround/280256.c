#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 3);
    requires (1 <= (b) && (b) <= 3);
    ensures \result == (a * b * 2 % 2 == 1);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    unsigned int product_val;
    unsigned int doubled;
    unsigned int remainder;
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 3);
    //@ assert (1 <= (b) && (b) <= 3);
    
    //@ assert ((a) * (b)) <= 9;
    product_val = a * b;
    
    //@ assert product_val <= 9;
    doubled = product_val * 2;
    
    //@ assert doubled <= 18;
    remainder = doubled % 2;
    
    //@ assert remainder == 0;
    result = (remainder == 1);
    
    return result;
}
