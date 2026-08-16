#include <stdbool.h>

/*@
    requires 0 <= X <= 1;
    requires X == (int)X;
    ensures (X == 0 ==> \result == 1);
    ensures (X == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int X)
{
    //@ assert ((X) == 0 || (X) == 1);
    //@ assert (1 - (X)) == 0 || (1 - (X)) == 1;
    return 1 - X;
}
