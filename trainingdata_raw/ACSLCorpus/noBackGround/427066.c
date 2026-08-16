#include <stdbool.h>

/*@
    requires 0 <= x <= 1;
    ensures ((x) == 0) ==> \result == 1;
    ensures ((x) == 1) ==> \result == 0;
*/
int func(int x)
{
    int res;

    //@ assert x == 0 || x == 1;
    
    if (x == 0) {
        //@ assert ((x) == 0);
        res = 1;
    } else {
        //@ assert ((x) == 1);
        res = 0;
    }
    
    return res;
}
