#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n <= 10000;

    logic integer div3(integer n) = n / 3;

    lemma div3_bounds:
        \forall integer n; is_valid_n(n) ==> 0 <= div3(n) <= 3333;

    lemma cube_bound:
        \forall integer e; 0 <= e <= 3333 ==> e * e * e <= 3333 * 3333 * 3333;
*/

/*@
    requires is_valid_n(n);
    ensures \result == div3(n) * div3(n) * div3(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t e = 0;
    int64_t temp_n = n;

    /*@
        loop invariant 0 <= e <= div3(n);
        loop invariant temp_n == n - 3 * e;
        loop invariant is_valid_n(n);
        loop assigns e, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
        e += 1;
    }

    //@ assert e >= 0 && e <= 3333;
    //@ assert e * e <= 3333 * 3333;
    //@ assert e * e * e <= 3333 * 3333 * 3333;

    return e * e * e;
}

int main()
{
    return 0;
}
