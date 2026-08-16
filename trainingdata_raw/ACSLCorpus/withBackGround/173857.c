#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer initial_product(integer r) = 2 * 314159 * r;

    lemma division_correctness:
        \forall integer r, ans, temp;
        valid_range(r) && ans * 100000 + temp == initial_product(r) && 0 <= temp < 100000 ==>
        ans == 2 * 314159 * r / 100000;
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * 314159 * r / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 314159;
    int64_t ans = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 100000;

    /*@
        loop invariant valid_range(r);
        loop invariant 0 <= ans;
        loop invariant 0 <= temp;
        loop invariant divisor == 100000;
        loop invariant ans * 100000 + temp == 2 * 314159 * r;
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        ans += 1;
        //@ assert ans * 100000 + temp == 2 * 314159 * r;
    }

    //@ assert ans * 100000 + temp == 2 * 314159 * r;
    //@ assert temp < divisor;
    //@ assert ans == 2 * 314159 * r / 100000;

    return ans;
}
