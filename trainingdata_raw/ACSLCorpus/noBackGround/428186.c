#include <stdbool.h>

/*@
    requires 0 <= X <= 9;
    requires 0 <= A <= 9;
    ensures (X < A ==> \result == 0) && (X >= A ==> \result == 10);
*/
int func(int X, int A)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 0 <= X <= 9 && 0 <= A <= 9;

    if (X < A)
    {
        result = 0;
    }
    else
    {
        //@ assert X >= A;
        result = 10;
    }

    return result;
}
