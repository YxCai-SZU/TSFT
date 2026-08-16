#include <stdbool.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures \result >= 1 && \result <= 10;
    ensures (x % 10 == 0 ==> \result == 1) && (x % 10 != 0 ==> \result == 1);
*/
int func(int x)
{
    int result;

    result = 1;

    //@ assert x % 10 == 0 ==> result == 1;
    //@ assert x % 10 != 0 ==> result == 1;
    //@ assert (x % 10 == 0 ==> result == 1) && (x % 10 != 0 ==> result == 1);

    return result;
}
