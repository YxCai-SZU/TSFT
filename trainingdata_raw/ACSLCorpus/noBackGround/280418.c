#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 1 <= x <= n;
    requires \valid(an + (0 .. n-1));
    requires \valid(am + (0 .. m-1));
    requires ((n) >= 0 &&
        \forall integer i; 0 <= i < (n) ==> (1) <= (an)[i] && (an)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (an)[i] != (an)[j]);
    requires ((m) >= 0 &&
        \forall integer i; 0 <= i < (m) ==> (1) <= (am)[i] && (am)[i] <= (m) &&
        \forall integer i, j; 0 <= i < j < (m) ==> (am)[i] != (am)[j]);
    ensures \result == \true <==> ((x) == (an[n-1]) || ((x) != (an[n-1]) && (an[n-1]) == (am[m-1])));
    assigns \nothing;
*/
bool func(int n, int m, int x, int *an, int *am)
{
    int an_last;
    int am_last;

    //@ assert n > 0 && m > 0;
    an_last = an[n - 1];
    am_last = am[m - 1];

    //@ assert an_last >= 1 && an_last <= n;
    return x == an_last || (x != an_last && an_last == am_last);
}
