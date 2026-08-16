#include <limits.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures ((m) >= 13 && (n) > 9) ==> \result == 0;
    ensures ((m) >= 7 && (m) < 13 && (n) > 9) ==> \result == 1;
    ensures ((m) >= 4 && (m) < 7 && (n) > 9) ==> \result == 2;
    ensures ((m) < 4 && (n) > 9) ==> \result == 3;
    ensures ((n) <= 9) ==> \result == 4;
*/
int func(int n, int m)
{
    int result;

    //@ assert 1 <= n <= 20 && 1 <= m <= 20;

    if (m >= 13 && n > 9)
    {
        //@ assert ((m) >= 13 && (n) > 9);
        result = 0;
    }
    else if (m >= 7 && m < 13 && n > 9)
    {
        //@ assert ((m) >= 7 && (m) < 13 && (n) > 9);
        result = 1;
    }
    else if (m >= 4 && m < 7 && n > 9)
    {
        //@ assert ((m) >= 4 && (m) < 7 && (n) > 9);
        result = 2;
    }
    else if (m < 4 && n > 9)
    {
        //@ assert ((m) < 4 && (n) > 9);
        result = 3;
    }
    else
    {
        //@ assert ((n) <= 9);
        result = 4;
    }

    return result;
}
