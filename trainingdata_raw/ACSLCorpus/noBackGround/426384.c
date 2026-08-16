#include <stdbool.h>

/*@
    requires ((x) <= 0xffff) && ((y) <= 0xffff);
    ensures \result == ((unsigned long long)x * y <= (unsigned long long)0xffff * 0xffff);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    //@ assert ((x) <= 0xffff);
    //@ assert ((y) <= 0xffff);
    //@ assert (unsigned long long)x * y <= (unsigned long long)0xffff * 0xffff;
    
    return (unsigned long long)x * y <= (unsigned long long)0xffff * 0xffff;
}
