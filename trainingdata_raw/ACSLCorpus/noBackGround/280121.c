#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result <= m;
    ensures (n == 1 && m == 1) ==> \result == 0;
    ensures (n == 1 && m != 1) ==> \result == 1;
    ensures (n != 1 && m == 1) ==> \result == 1;
    ensures (n != 1 && m != 1) ==> \result == 2;
*/
int func(int n, int m)
{
    int result;

    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);

    if (n == 1 && m == 1)
    {
        result = 0;
        //@ assert result == 0;
    }
    else if (n == 1 || m == 1)
    {
        //@ assert 1 <= n && n <= 100;
        //@ assert 1 <= m && m <= 100;
        //@ assert n == 1 || m == 1;
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        //@ assert 1 <= n && n <= 100;
        //@ assert 1 <= m && m <= 100;
        //@ assert n != 1 && m != 1;
        result = 2;
        //@ assert result == 2;
    }

    //@ assert result >= 0;
    //@ assert result <= n;
    //@ assert result <= m;
    return result;
}
