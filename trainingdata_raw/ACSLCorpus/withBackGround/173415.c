#include <stddef.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 10000;

    logic integer func_spec(integer n) =
        1000 * (n / 1000) + 500 * ((n % 1000) / 500) + 100 * (((n % 1000) % 500) / 100);

    lemma func_lemma:
        \forall integer n; valid_n(n) ==> func_spec(n) == 1000 * (n / 1000) + 500 * ((n % 1000) / 500) + 100 * (((n % 1000) % 500) / 100);
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result = 0;
    size_t remaining = n;
    size_t count_1000;
    size_t count_500;
    size_t count_100;

    // Handle 1000-yen bills
    count_1000 = n / 1000;
    result += count_1000 * 1000;
    remaining -= count_1000 * 1000;

    // Handle 500-yen bills
    count_500 = remaining / 500;
    result += count_500 * 500;
    remaining -= count_500 * 500;

    // Handle 100-yen bills
    count_100 = remaining / 100;
    result += count_100 * 100;
    remaining -= count_100 * 100;

    //@ assert remaining == n - (count_1000 * 1000 + count_500 * 500 + count_100 * 100);
    //@ assert result == func_spec(n);

    return result;
}
