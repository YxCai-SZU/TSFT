#include <stdbool.h>

/*@
    requires 1 <= a && a <= 3;
    requires 1 <= b && b <= 3;
    ensures \result == ((a * b * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int ab;
    unsigned int abb;
    bool result;

    //@ assert (1 <= (a) && (a) <= 3 && 1 <= (b) && (b) <= 3);
    
    ab = a * b;
    //@ assert 1 <= ab && ab <= 9;
    
    abb = ab * b;
    //@ assert 1 <= abb && abb <= 27;
    
    result = (abb % 2 == 0);
    //@ assert abb == a * b * b;
    
    return result;
}
