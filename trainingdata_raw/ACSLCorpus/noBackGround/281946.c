#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(a + (0..4));
    requires (\forall integer i; 0 <= i < (5)-1 ==> (a)[i] < (a)[i+1]);
    requires ((5) == 5 &&
        (a)[0] >= 0 &&
        (a)[4] <= 123 &&
        (a)[1] - (a)[0] <= 10 &&
        (a)[2] - (a)[1] <= 10 &&
        (a)[3] - (a)[2] <= 10 &&
        (a)[4] - (a)[3] <= 10);
    requires k <= 123;
    ensures \result == (a[4] - a[0] <= k);
*/
bool func(int* a, int k)
{
    int diff;
    bool result;

    diff = a[4] - a[0];
    //@ assert diff == a[4] - a[0];

    if (diff > k)
    {
        result = false;
        //@ assert !(a[4] - a[0] <= k);
    }
    else
    {
        //@ assert a[4] - a[0] <= k;
        result = true;
    }

    return result;
}
