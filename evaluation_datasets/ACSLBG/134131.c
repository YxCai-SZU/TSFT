#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= b && b <= 100;

    predicate ans_condition(integer ans, integer a, integer b) =
        ans == -1 ||
        (1 <= ans && ans <= 1000 &&
         (integer)ans * 8 / 100 == a &&
         (integer)ans * 10 / 100 == b);

    lemma ans_range: \forall integer ans, a, b;
        ans_condition(ans, a, b) ==> (ans >= 1 || ans == -1);
*/


int32_t func(uint64_t a, uint64_t b)
{
    uint64_t x;
    int32_t ans;

    x = 1;
    ans = -1;

    
    while (x <= 1000)
    {
        uint64_t ax = x * 8 / 100;
        uint64_t by = x * 10 / 100;

        //@ assert ax == (x * 8) / 100 && by == (x * 10) / 100;

        if (ax == a && by == b)
        {
            ans = (int32_t)x;
            break;
        }

        x = x + 1;
    }

    //@ assert ans_condition(ans, a, b);
    return ans;
}
