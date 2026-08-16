/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer total_positive(integer i) = i * 800;
    logic integer total_negative(integer j) = j * 200;

    lemma subtraction_correct:
        \forall integer n, integer ans, integer sub;
        valid_n(n) && ans == total_positive(n) && sub == total_negative(n / 15) ==>
        ans - sub == n * 800 - (n / 15) * 200;
*/

#include <stdint.h>

/*@
    requires valid_n(n);
    ensures \result == n * 800 - (n / 15) * 200;
*/
int32_t func(uint32_t n)
{
    int32_t ans = 0;
    uint32_t i = 0;
    int32_t sub = 0;
    uint32_t j = 0;

    //@ assert ans == total_positive(i);
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == total_positive(i);
        loop invariant valid_n(n);
        loop assigns ans, i;
    */
    while (i < n)
    {
        //@ assert i < n;
        ans += 800;
        i += 1;
        //@ assert ans == total_positive(i);
    }
    //@ assert ans == total_positive(n);

    //@ assert sub == total_negative(j);
    /*@
        loop invariant 0 <= j <= n / 15;
        loop invariant sub == total_negative(j);
        loop invariant valid_n(n);
        loop assigns sub, j;
    */
    while (j < n / 15)
    {
        //@ assert j < n / 15;
        sub += 200;
        j += 1;
        //@ assert sub == total_negative(j);
    }
    //@ assert sub == total_negative(n / 15);

    ans -= sub;
    //@ assert ans == total_positive(n) - total_negative(n / 15);
    return ans;
}
