#include <stdbool.h>
/*@
    requires (3 <= (n) && (n) <= 20 &&
        \valid((ps) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> (ps)[i] >= 1 && (ps)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (ps)[i] != (ps)[j]));
    ensures ((\result) == ((n) == 2 || ((n) > 2 && (((ps))[((n))-1] - ((ps))[0]) < (n) - 1)));
    assigns \nothing;
*/
bool func(int n, int *ps)
{
    // Variable declarations at scope top
    bool result;

    //@ assert n >= 3 && n <= 20;
    //@ assert \valid(ps + (0 .. n-1));
    //@ assert \forall integer i; 0 <= i < n ==> ps[i] >= 1 && ps[i] <= n;
    //@ assert \forall integer i, j; 0 <= i < j < n ==> ps[i] != ps[j];

    if (n == 2)
    {
        result = true;
    }
    else if (n > 2)
    {
        //@ assert n > 2;
        result = (ps[n - 1] - ps[0]) < (n - 1);
    }
    else
    {
        //@ assert n == 2 || (n > 2 && ps[n-1] - ps[0] < n - 1);
        result = false;
    }

    //@ assert ((result) == ((n) == 2 || ((n) > 2 && (((ps))[((n))-1] - ((ps))[0]) < (n) - 1)));
    return result;
}
