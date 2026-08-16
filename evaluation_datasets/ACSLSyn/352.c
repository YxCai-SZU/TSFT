#include <stdint.h>
#include <stdbool.h>

/*@
    predicate is_within_bounds(integer x, integer y) =
        1 <= x && x <= 5 && 1 <= y && y <= 5;

    logic integer max_product(integer x, integer y) = x * y;

    lemma product_bound: \forall integer x, y; is_within_bounds(x, y) ==> max_product(x, y) <= 25;
*/

unsigned int non_linear_arith_example(unsigned int x, unsigned int y)
{
    unsigned int ret;

    //@ assert x > 0 && y > 0;
    //@ assert is_within_bounds(x, y);
    //@ assert x * y <= 25;

    ret = x * y;
    return ret;
}

void bound_check(unsigned int x, unsigned int y)
{
    //@ assert 1 <= x && x <= 5;
    //@ assert 1 <= y && y <= 5;
    //@ assert is_within_bounds(x, y);
    //@ assert x * y <= 25;
}

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_ans(integer a, integer b) = a - (b * 2);

    lemma ans_nonnegative_or_negative:
        \forall integer a, b, ans;
            valid_range(a, b) && ans == compute_ans(a, b) ==>
            ans >= 0 || ans < 0;

    lemma ans_nonnegative_identity:
        \forall integer a, b, ans;
            valid_range(a, b) && ans == compute_ans(a, b) && ans >= 0 ==>
            ans == compute_ans(a, b);

    lemma ans_negative_zero:
        \forall integer a, b, ans;
            valid_range(a, b) && ans == compute_ans(a, b) && ans < 0 ==>
            0 == 0;
*/

int64_t func_int64(int64_t a, int64_t b)
{
    int64_t ans;
    int64_t res;

    ans = a - (b * 2);

    //@ assert ans >= 0 || ans < 0;
    //@ assert ans >= 0 ==> ans == a - (b * 2);
    //@ assert ans < 0 ==> 0 == 0;

    if (ans >= 0)
    {
        res = ans;
    }
    else
    {
        res = 0;
    }

    //@ assert res >= 0;
    //@ assert res == a - (b * 2) || res == 0;

    return res;
}

/*@ predicate is_valid_range(integer k) = 1 <= k <= 100; */
/*@ predicate is_valid_x(integer x) = 1 <= x <= 100000; */
/*@ logic integer compute_sum(integer k) = 500 * k; */

bool func_bool(int k, int x)
{
    int sum;
    bool result;
    
    sum = 500 * k;
    result = sum >= x;
    return result;
}

/*@ predicate vec_len(integer len) = len == 5; */
/*@ predicate valid_element(integer elem) = 0 <= elem <= 123; */
/*@ predicate valid_k(integer k) = 0 <= k <= 123; */

bool func_2(int *a, int k)
{
    int array[5];
    int i;
    int first;
    int last;
    bool result;
    
    i = 0;
    while (i < 5)
    {
        array[i] = a[i];
        i = i + 1;
    }
    
    first = array[0];
    last = array[4];
    result = last - first <= k;
    return result;
}

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
    
    logic integer subtract(integer n, integer k) = n - k;
*/

bool func_loop(int n, int m)
{
    int temp_n = n;
    int count = 0;
    
    while (count < m && temp_n >= 1)
    {
        //@ assert count < m && temp_n >= 1;
        temp_n -= 1;
        count += 1;
    }
    
    //@ assert temp_n == 0 ==> n == m;
    //@ assert temp_n != 0 ==> n != m;
    return temp_n == 0;
}

bool GameScoreValidator(unsigned int x, unsigned int y,
                        int64_t a, int64_t b,
                        int k_range, int x_thresh,
                        int *arr, int k_diff,
                        int n, int m)
{
    unsigned int product = non_linear_arith_example(x, y);
    bound_check(x, y);
    //@ assert product == x * y && product <= 25;

    int64_t adjusted = func_int64((int64_t)product, b);
    //@ assert adjusted >= 0;
    //@ assert adjusted == (int64_t)product - (b * 2) || adjusted == 0;

    bool threshold_ok = func_bool(k_range, x_thresh);
    //@ assert threshold_ok == (500 * k_range >= x_thresh);

    bool array_ok = func_2(arr, k_diff);
    //@ assert array_ok == (arr[4] - arr[0] <= k_diff);

    bool eq_ok = func_loop(n, m);
    //@ assert eq_ok == (n == m);

    //@ assert (product <= 25 && adjusted >= 0 && threshold_ok && array_ok && eq_ok) ==> 1 == 1;

    return 1;
}
