#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20);
    requires (1 <= (m) <= 20);
    ensures (1 <= m && m <= 10) ==> \result == n + m;
    ensures (m == 11) ==> \result == n + 1;
    ensures (12 <= m && m <= 20) ==> \result == n + (m - 10);
    ensures \result == ((1 <= (m) && (m) <= 10) ? (n) + (m) :
        ((m) == 11) ? (n) + 1 :
        (n) + ((m) - 10));
*/
int func(int n, int m)
{
    int res;

    if (m >= 1 && m <= 10)
    {
        //@ assert 1 <= m && m <= 10;
        res = n + m;
        //@ assert res == ((1 <= (m) && (m) <= 10) ? (n) + (m) :         ((m) == 11) ? (n) + 1 :         (n) + ((m) - 10));
    }
    else if (m == 11)
    {
        //@ assert m == 11;
        res = n + 1;
        //@ assert res == ((1 <= (m) && (m) <= 10) ? (n) + (m) :         ((m) == 11) ? (n) + 1 :         (n) + ((m) - 10));
    }
    else
    {
        //@ assert 12 <= m && m <= 20;
        res = n + (m - 10);
        //@ assert res == ((1 <= (m) && (m) <= 10) ? (n) + (m) :         ((m) == 11) ? (n) + 1 :         (n) + ((m) - 10));
    }

    //@ assert res == ((1 <= (m) && (m) <= 10) ? (n) + (m) :         ((m) == 11) ? (n) + 1 :         (n) + ((m) - 10));
    return res;
}
