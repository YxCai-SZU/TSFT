#include <limits.h>

/*@
    requires (1 <= (n) <= 20);
    requires (1 <= (m) <= 20);
    ensures \result == (((m) > 0 && (m) <= 10) ? (n) + ((m) * 2) : (n) + (m));
    ensures \result <= 40;
*/
int func(int n, int m)
{
    int result = 0;

    //@ assert (1 <= (n) <= 20);
    //@ assert (1 <= (m) <= 20);

    if (m > 0 && m <= 10) {
        //@ assert 1 <= n && n <= 20;
        //@ assert 1 <= m && m <= 10;
        //@ assert n + (m * 2) <= 40;
        result = n + (m * 2);
    } else if (m > 10) {
        //@ assert 1 <= n && n <= 20;
        //@ assert 11 <= m && m <= 20;
        //@ assert n + m <= 40;
        result = n + m;
    }

    //@ assert (m > 0 && m <= 10) ==> result == n + (m * 2);
    //@ assert (m > 10) ==> result == n + m;
    //@ assert result == (((m) > 0 && (m) <= 10) ? (n) + ((m) * 2) : (n) + (m));
    //@ assert result <= 40;

    return result;
}
