#include <stdbool.h>

/*@
    requires (0 <= (x) <= 1 && 0 <= (y) <= 1);
    ensures \result == (((x) == 1 && (y) == 1) || ((x) == 0 && (y) == 0) ? 1 : 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    //@ assert 0 <= x <= 1;
    //@ assert 0 <= y <= 1;
    
    return (x == 1 && y == 1) || (x == 0 && y == 0);
}
