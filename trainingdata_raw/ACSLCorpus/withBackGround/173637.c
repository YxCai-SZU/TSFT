#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer x) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000;

    predicate is_valid_vec(integer n, int *vec) =
        \valid(vec + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= vec[i] && vec[i] <= 100;

    logic integer vec_len(integer n) = n;

    lemma loop_invariant_maintains_bounds:
        \forall integer n, x, index, count, d;
        0 <= index <= n &&
        d >= 0 &&
        count >= 0 &&
        count <= index &&
        is_valid_params(n, x) ==>
        count <= n;
*/

/*@
    requires is_valid_params(n, x);
    requires is_valid_vec(n, l_vec);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int x, int *l_vec)
{
    int d = 0;
    int count = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant d >= 0;
        loop invariant count >= 0;
        loop invariant count <= index;
        loop invariant index <= n;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= l_vec[i] && l_vec[i] <= 100;
        loop invariant is_valid_params(n, x);
        loop invariant is_valid_vec(n, l_vec);
        loop invariant d <= x + 100;
        loop assigns d, count, index;
        loop variant n - index;
    */
    while (d <= x && index < n)
    {
        //@ assert count >= 0;
        count += 1;
        //@ assert d >= 0;
        d += l_vec[index];
        //@ assert index >= 0;
        index += 1;
    }

    //@ assert count <= n;
    return count;
}
