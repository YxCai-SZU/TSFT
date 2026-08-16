#include <stdbool.h>

/*@
    requires (1 <= (x) <= 10);
    ensures ((\result) == (x) + 1 || (\result) == (x));
    assigns \nothing;
*/
int func(int x)
{
    int res;
    
    //@ assert (1 <= (x) <= 10);
    
    if (x == 5) {
        //@ assert x + 1 <= 11;
        res = x + 1;
    } else {
        res = x;
    }
    
    //@ assert ((res) == (x) + 1 || (res) == (x));
    return res;
}
