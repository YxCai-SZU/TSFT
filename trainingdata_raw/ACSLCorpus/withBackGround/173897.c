#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer div2(integer n) = n / 2;
    logic integer div3(integer n) = n / 3;
    logic integer mod2(integer n) = n % 2;
    logic integer mod3(integer n) = n % 3;

    lemma div2_range: \forall integer n; is_valid_n(n) ==> 0 <= div2(n) <= 50000;
    lemma div3_range: \forall integer n; is_valid_n(n) ==> 0 <= div3(n) <= 33333;
    lemma mod2_range: \forall integer n; is_valid_n(n) ==> 0 <= mod2(n) <= 1;
    lemma mod3_range: \forall integer n; is_valid_n(n) ==> 0 <= mod3(n) <= 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 0 || \result == 1;
*/
int64_t func(int64_t n)
{
    int64_t a;
    int64_t b;
    int64_t temp_n;
    int64_t count_2;
    int64_t count_3;
    int64_t count_2_a;
    int64_t temp_a;
    int64_t count_3_b;
    int64_t temp_b;
    int64_t result;
    int64_t is_possible;
    int64_t temp_result;
    int64_t return_value;

    a = 0;
    b = 0;
    temp_n = n;
    count_2 = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 2 == n % 2;
        loop invariant 0 <= count_2 <= n / 2;
        loop invariant temp_n + 2 * count_2 == n;
        loop assigns temp_n, count_2;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count_2 += 1;
    }
    a = count_2;

    temp_n = n;
    count_3 = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 3 == n % 3;
        loop invariant 0 <= count_3 <= n / 3;
        loop invariant temp_n + 3 * count_3 == n;
        loop assigns temp_n, count_3;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
        count_3 += 1;
    }
    b = count_3;

    count_2_a = 0;
    temp_a = a;

    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 2 == a % 2;
        loop invariant 0 <= count_2_a <= a / 2;
        loop invariant temp_a + 2 * count_2_a == a;
        loop assigns temp_a, count_2_a;
    */
    while (temp_a >= 2)
    {
        temp_a -= 2;
        count_2_a += 1;
    }

    count_3_b = 0;
    temp_b = b;

    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop invariant 0 <= count_3_b <= b / 3;
        loop invariant temp_b + 3 * count_3_b == b;
        loop assigns temp_b, count_3_b;
    */
    while (temp_b >= 3)
    {
        temp_b -= 3;
        count_3_b += 1;
    }

    result = count_2_a + count_3_b;
    is_possible = 0;
    temp_result = result;

    /*@
        loop invariant 0 <= temp_result <= result;
        loop invariant temp_result % 2 == result % 2;
        loop invariant 0 <= is_possible <= result / 2;
        loop invariant temp_result + 2 * is_possible == result;
        loop assigns temp_result, is_possible;
    */
    while (temp_result >= 2)
    {
        temp_result -= 2;
        is_possible += 1;
    }

    if (is_possible >= n)
    {
        return_value = 1;
        //@ assert return_value == 1;
        return return_value;
    }
    else
    {
        return_value = 0;
        //@ assert return_value == 0;
        return return_value;
    }
}
