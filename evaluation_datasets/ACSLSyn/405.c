#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* Function 1: Calculate a combined result based on n and m */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer formula_result(integer n, integer m) =
        n * 2 <= m ? n + (m - n * 2) / 4 : m;

    lemma result_bounds: \forall integer n, m;
        valid_params(n, m) ==> 0 <= formula_result(n, m) && formula_result(n, m) <= n + m;
*/

size_t func1(size_t n, size_t m)
{
    size_t result;
    size_t temp_m;
    size_t count;

    //@ assert n * 2 <= 18446744073709551615;

    if (n * 2 <= m)
    {
        result = n;
        temp_m = m - n * 2;
        count = 0;

        while (temp_m >= 4)
        {
            temp_m -= 4;
            count += 1;
        }

        result += count;
        return result;
    }
    else
    {
        result = m;
        return result;
    }
}

/* Function 2: Check if x ends with 99 */
/*@
    predicate is_last_two_digits_99(integer x) =
        (x / 100) * 100 + 99 == x;
*/

unsigned int func2(unsigned int x)
{
    unsigned int n;
    unsigned int res;

    n = x / 100;
    //@ assert n * 100 <= 4294967295 - 99;
    //@ assert n * 100 + 99 <= 4294967295;

    if ((n * 100 + 99) == x)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }

    return res;
}

/* Function 3: Compare two combined numbers */
/*@
    predicate valid_range(integer v) = 1 <= v <= 9;

    logic integer combine(integer b, integer c) = b * 10 + c;
    logic integer scale(integer a) = a * 10;

    lemma combine_scale_diff:
        \forall integer a, integer b, integer c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        (combine(b, c) - scale(a) > 0) == ((b * 10 + c) - (a * 10) > 0);
*/

bool func3(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long x;
    unsigned long long y;
    bool result;

    x = b * 10 + c;
    y = a * 10;

    //@ assert x == b * 10 + c;
    //@ assert y == a * 10;

    if (x >= y)
    {
        result = (x - y > 0);
    }
    else
    {
        result = false;
    }

    //@ assert result == ((b * 10 + c) - (a * 10) > 0);
    return result;
}

/* Function 4: Find an index in array with specific property */
/*@
    predicate valid_array(size_t n, int *h) =
        n >= 1 && n <= 100000 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 100000;

    logic integer max(integer a, integer b) = a > b ? a : b;
*/

size_t func4(size_t n, int *h) {
    size_t l = 0;
    size_t r = n - 1;
    size_t res = 0;


    while (l < r) {
        int l_h = h[l];
        int r_h = h[r];
        int min_h = l_h < r_h ? l_h : r_h;
        int max_h = l_h > r_h ? l_h : r_h;

        if (min_h == max_h) {
            //@ assert l >= 0 && l < n;
            res = res > l ? res : l;
            break;
        } else if (min_h == l_h) {
            //@ assert l >= 0 && l < n;
            res = res > l ? res : l;
            l++;
        } else {
            //@ assert r >= 0 && r < n;
            res = res > r ? res : r;
            r--;
        }
    }

    //@ assert res >= 0 && res < n;
    return res;
}

/* Synthesized function: Process a sequence of data items to compute a combined result
   Scenario: In a data processing pipeline, we have a sequence of items. Each item has
   parameters n, m, x, a, b, c, and an array h. The function computes:
   - For each item, compute a base value from func1(n, m)
   - Check if x ends with 99 using func2(x)
   - Compare two derived values using func3(a, b, c)
   - Find an index from the array using func4(n, h)
   - Combine these results to produce a final output that satisfies a high-level invariant

   The core property: The output result is always within a valid range and the combined
   logic ensures that the final result is a valid index or a valid computed value.
*/

size_t synthesized_func(size_t n, size_t m, unsigned int x, 
                        unsigned long long a, unsigned long long b, unsigned long long c,
                        size_t arr_n, int *h) {
    size_t result = 0;
    size_t base;
    unsigned int check;
    bool compare;
    size_t index;

    base = func1(n, m);
    //@ assert base >= 0 && base <= n + m;

    check = func2(x);
    //@ assert (check == 1) ==> is_last_two_digits_99(x);
    //@ assert (check == 0) ==> !is_last_two_digits_99(x);

    compare = func3(a, b, c);
    //@ assert compare == ((b * 10 + c) - (a * 10) > 0);

    index = func4(arr_n, h);
    //@ assert index >= 0 && index < arr_n;

    if (check == 1 && compare) {
        result = base + index;
    } else {
        result = base;
    }

    //@ assert result >= 0 && result <= n + m + arr_n;  // High-level property
    return result;
}
