#include <stdbool.h>

/*@
    requires (1 <= (p0) <= 100);
    requires (1 <= (p1) <= 100);
    ensures \result == ((p0 + 1) / 2 >= p1);
    assigns \nothing;
*/
bool func(unsigned int p0, unsigned int p1)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int temp;

    //@ assert p0 >= 1 && p0 <= 100;
    //@ assert p1 >= 1 && p1 <= 100;
    
    //@ assert p0 + 1 <= 101;
    temp = (p0 + 1) / 2;
    result = (temp >= p1);
    
    //@ assert result == ((p0 + 1) / 2 >= p1);
    return result;
}
