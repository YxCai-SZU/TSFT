#include <stdint.h>
#include <stdbool.h>

/* ACSL specifications and functions from snippet 1 */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_result(integer a, integer b) =
        (a + b) % 2 == 0 ? (a + b) / 2 : (a + b) / 2 + 1;

    lemma result_bound:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> compute_result(a, b) <= 100;
*/

uint32_t func1(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;

    sum = a + b;
    //@ assert 2 <= sum <= 200;

    result = sum / 2;
    //@ assert 1 <= result <= 100;

    if (sum % 2 != 0) {
        return result + 1;
    } else {
        return result;
    }
}

/* ACSL specifications and functions from snippet 2 */
/*@
    predicate is_in_range(integer a) =
        1 <= a && a <= 5000;

    predicate is_c_in_range(integer c) =
        1 <= c && c <= 100000;

    logic integer min_val(integer a, integer b) =
        a < b ? a : b;
*/

bool func2(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min;
    bool result;

    //@ assert is_in_range(a) && is_in_range(b) && is_c_in_range(c);
    
    if (a < b) {
        min = a;
    } else {
        min = b;
    }

    //@ assert min == min_val(a, b);

    if (min >= c) {
        //@ assert min >= c;
        return true;
    }

    //@ assert min < c;
    result = (c <= a + b);
    return result;
}

/* ACSL specifications and functions from snippet 3 */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer remainder_func(integer n) = n % 1000;

    logic integer result_func(integer n) =
        remainder_func(n) == 0 ? 0 : 1000 - remainder_func(n);

    lemma remainder_range: \forall integer n; is_valid_n(n) ==> 0 <= remainder_func(n) && remainder_func(n) < 1000;
*/

int64_t func3(int64_t n)
{
    uint64_t n_unsigned;
    uint64_t remainder;
    int64_t result;

    //@ assert is_valid_n(n);
    n_unsigned = (n < 0) ? (uint64_t)(-n) : (uint64_t)n;
    remainder = n_unsigned % 1000;

    if (remainder == 0) {
        //@ assert remainder_func(n) == 0;
        result = 0;
    } else {
        //@ assert remainder_func(n) != 0;
        result = 1000 - (int64_t)remainder;
    }

    //@ assert result == result_func(n);
    return result;
}

/* ACSL specifications and functions from snippet 4 */
/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;
*/

bool func4(int a, int b, int c)
{
    bool ans = true;
    
    //@ assert ans == true;
    
    if (a == b)
    {
        ans = ans && true;
    }
    else
    {
        ans = ans && false;
    }
    
    //@ assert ans == (a == b);
    
    if (b == c)
    {
        ans = ans && true;
    }
    else
    {
        ans = ans && false;
    }
    
    //@ assert ans == (a == b && b == c);
    
    return ans;
}

bool quality_control_system(int a, int b, int c, uint32_t x, uint32_t y, unsigned int d, int64_t n)
{
    bool measurements_equal;
    uint32_t rounded_average;
    bool sum_check;
    int64_t rounding_offset;
    bool final_result;

    measurements_equal = func4(a, b, c);
    //@ assert measurements_equal == (a == b && b == c);

    rounded_average = func1(x, y);
    //@ assert rounded_average <= 100;

    sum_check = func2(x, y, d);
    //@ assert sum_check == (d <= x + y);

    rounding_offset = func3(n);
    //@ assert rounding_offset == result_func(n);

    final_result = measurements_equal && (rounded_average <= 100) && sum_check && (rounding_offset >= 0 && rounding_offset < 1000);

    //@ assert final_result == ( (a == b && b == c) && (rounded_average <= 100) && (d <= x + y) && (rounding_offset >= 0 && rounding_offset < 1000) );

    return final_result;
}
