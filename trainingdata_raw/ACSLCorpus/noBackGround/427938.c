#include <stdbool.h>

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1);
    ensures (x == 1 ==> \result == 0);
*/
int func(int x)
{
    int ret;

    //@ assert x == 0 || x == 1;

    /*@
        assert x == 0 ==> 1 - x == 1;
    */
    /*@
        assert x == 1 ==> 1 - x == 0;
    */

    ret = 1 - x;
    return ret;
}
