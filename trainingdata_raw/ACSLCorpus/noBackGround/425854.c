#include <stdbool.h>

/*@
    requires (10 <= (a) <= 99);
    assigns \nothing;
    ensures \result == (((a) / 10) == 7 || ((a) % 10) == 7);
*/
bool func(unsigned int a)
{
    // Variable declarations at top of scope
    unsigned int d1;
    unsigned int d2;
    bool result;
    
    //@ assert 10 <= a <= 99;
    
    d1 = a / 10;
    d2 = a % 10;
    
    //@ assert d1 <= 9;
    //@ assert d2 <= 9;
    
    result = (d1 == 7) || (d2 == 7);
    
    //@ assert result == (((a) / 10) == 7 || ((a) % 10) == 7);
    return result;
}
