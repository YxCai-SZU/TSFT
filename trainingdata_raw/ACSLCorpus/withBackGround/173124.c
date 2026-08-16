#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 10000;

    logic integer half_plus_one(integer n) = (n + 1) / 2;

    lemma half_positive: \forall integer n; valid_range(n) ==> half_plus_one(n) > 0;
    lemma half_bounded: \forall integer n; valid_range(n) ==> half_plus_one(n) <= 5000;
*/

/*@
    requires valid_range(n);
    ensures \result == half_plus_one(n);
    ensures \result > 0;
    ensures \result <= 5000;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t temp;
    int64_t count;

    result = 0;
    temp = n + 1;
    count = 0;

    /*@
        loop invariant 0 <= temp <= n + 1;
        loop invariant 0 <= count <= half_plus_one(n);
        loop invariant temp == n + 1 - 2 * count;
        loop invariant valid_range(n);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }
    result = count;

    //@ assert result == half_plus_one(n);
    //@ assert result > 0;
    //@ assert result <= 5000;

    return result;
}
