#include <stdbool.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer division_by_15(integer n) = n / 15;

    logic integer target_result(integer n) = n * 800 - division_by_15(n) * 200;

    lemma division_property:
        \forall integer n, count, n_mut;
        valid_n(n) && 0 <= n_mut && n_mut <= n &&
        count <= division_by_15(n) && n_mut == n - count * 15 ==>
        n_mut < 15 ==> count == division_by_15(n);
*/

/*@
    requires valid_n(n);
    ensures \result == target_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int n_mut;
    int count;

    //@ assert valid_n(n);
    result = 0;
    n_mut = n;
    count = 0;

    /*@
        loop invariant valid_n(n);
        loop invariant 0 <= n_mut && n_mut <= n;
        loop invariant count <= division_by_15(n);
        loop invariant n_mut == n - count * 15;
        loop assigns n_mut, count;
        loop variant n_mut;
    */
    while (n_mut >= 15)
    {
        n_mut = n_mut - 15;
        count = count + 1;
    }

    //@ assert n_mut == n - count * 15;
    //@ assert count == division_by_15(n);

    //@ assert n * 800 <= 100 * 800;
    //@ assert division_by_15(n) * 200 <= 100 * 200;
    //@ assert n * 800 >= division_by_15(n) * 200;

    result = n * 800 - count * 200;
    return result;
}
