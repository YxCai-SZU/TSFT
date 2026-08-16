#include <stdbool.h>

/*@
    predicate a_in_range(int *a, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n;

    predicate b_in_range(int *b, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= b[i] <= 50;

    predicate c_in_range(int *c, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= c[i] <= 50;

    predicate a_distinct(int *a, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];

    lemma ret_bound:
        \forall integer i, n, ret;
        0 <= i <= n && ret >= 0 && ret <= i * 100 ==>
        ret <= n * 100;
*/

/*@
    requires 1 <= n <= 20;
    requires \valid(a + (0 .. n-1));
    requires \valid(b + (0 .. n-1));
    requires \valid(c + (0 .. n-1));
    requires a_in_range(a, n);
    requires b_in_range(b, n);
    requires c_in_range(c, n);
    requires a_distinct(a, n);
    ensures \result >= 0;
    ensures \result <= n * 100;
    assigns \nothing;
*/
int func(int n, int *a, int *b, int *c)
{
    int ret = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ret >= 0;
        loop invariant ret <= i * 100;
        loop invariant a_in_range(a, n);
        loop invariant b_in_range(b, n);
        loop invariant c_in_range(c, n);
        loop invariant a_distinct(a, n);
        loop assigns i, ret;
        loop variant n - i;
    */
    while (i < n)
    {
        int num = a[i];
        //@ assert 1 <= num <= n;
        ret = ret + c[num - 1];
        //@ assert ret >= 0;

        if (i > 0)
        {
            if (a[i] == a[i - 1] + 1)
            {
                ret = ret + b[num - 1];
                //@ assert ret >= 0;
            }
        }
        i = i + 1;
    }
    return ret;
}
