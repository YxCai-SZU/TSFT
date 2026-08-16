#include <limits.h>

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    requires 1 <= d <= 5000;
    ensures \result >= (a < b ? a : b);
    ensures \result >= (c < d ? c : d);
    ensures \result <= a + c;
    ensures \result <= b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int train1;
    int train2;
    int res;

    //@ assert 1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 5000 && 1 <= d <= 5000;

    train1 = (a < b) ? a : b;
    //@ assert (((a) < (b) ==> (train1) >= (a)) && ((a) >= (b) ==> (train1) >= (b)));

    train2 = (c < d) ? c : d;
    //@ assert (((c) < (d) ==> (train2) >= (c)) && ((c) >= (d) ==> (train2) >= (d)));

    //@ assert train1 >= (a < b ? a : b);
    //@ assert train2 >= (c < d ? c : d);

    res = train1 + train2;
    //@ assert res == train1 + train2;

    //@ assert res <= a + c;
    //@ assert res <= b + d;

    return res;
}
