#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures ((\result) + (a) + (b) == 6) && ((\result) == 1 || (\result) == 2 || (\result) == 3);
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int res;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    //@ assert ((a) != (b));
    
    res = 6 - a - b;
    
    //@ assert res == 6 - a - b;
    //@ assert ((res) + (a) + (b) == 6);
    //@ assert ((res) == 1 || (res) == 2 || (res) == 3);
    
    return res;
}
