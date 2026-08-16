#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200 &&
        \valid((v) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (v)[k] >= 1 && (v)[k] <= 1000);
    ensures \result >= 0 && \result <= 1000;
    ensures \exists integer i, j; 0 <= i < n && 0 <= j < n && \result == v[j] - v[i];
*/
int func(size_t n, int *v)
{
    int min_val;
    int max_val;
    size_t i;

    //@ assert ((n) >= 1 && (n) <= 200 &&         \valid((v) + (0 .. (n)-1)) &&         \forall integer k; 0 <= k < (n) ==> (v)[k] >= 1 && (v)[k] <= 1000);
    min_val = v[0];
    max_val = v[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant ((n) >= 1 && (n) <= 200 &&
        \valid((v) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (v)[k] >= 1 && (v)[k] <= 1000);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min_val) <= (v)[k]);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max_val) >= (v)[k]);
        loop invariant min_val >= 1 && max_val <= 1000;
        loop invariant (\exists integer x, y; 0 <= x < (i) && 0 <= y < (i) && (max_val) == (v)[y] && (min_val) == (v)[x]);
        loop assigns i, min_val, max_val;
    */
    while (i < n)
    {
        int x = v[i];

        //@ assert x >= 1 && x <= 1000;
        if (x < min_val)
        {
            min_val = x;
        }
        if (x > max_val)
        {
            max_val = x;
        }
        i++;
    }

    int ret = max_val - min_val;
    //@ assert ret >= 0;
    //@ assert ret <= 1000;
    //@ assert \exists integer i, j; 0 <= i < n && 0 <= j < n && ret == v[j] - v[i];
    return ret;
}
