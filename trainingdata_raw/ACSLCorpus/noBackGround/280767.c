#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b * 2 % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product_val;
    unsigned int doubled;
    unsigned int remainder;
    bool result;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    
    // Apply lemma for current a and b
    //@ assert (1 <= (a) <= 3) && (1 <= (b) <= 3);
    //@ assert ((a) * (b)) <= 9;
    //@ assert a * b <= 9;
    
    product_val = a * b;
    doubled = product_val * 2;
    remainder = doubled % 2;
    result = (remainder != 0);
    
    return result;
}
