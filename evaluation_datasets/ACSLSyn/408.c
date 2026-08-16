#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ====== Original function 1: count_odd_in_even_positions ====== */

/*@ predicate valid_array(int *a, integer n) =
      n >= 1 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 100;
*/

/*@ predicate condition_holds(int *a, integer i) =
      i % 2 == 0 && (unsigned int)a[i] % 2 == 1;
*/

size_t count_odd_in_even_positions(size_t n, int *a)
{
    size_t ans = 0;
    size_t i = 0;
    
    while (i < n)
    {
        if (i % 2 == 0)
        {
            int x = a[i];
            //@ assert 1 <= x <= 100;
            if ((unsigned int)x % 2 == 1)
            {
                ans += 1;
                //@ assert ans > 0;
            }
        }
        i += 1;
    }
    return ans;
}

/* ====== Original function 2: date_check ====== */

/*@
    predicate is_valid_input(integer a, integer b) =
        1 <= a && a <= 12 && 1 <= b && b <= 31;
*/

int32_t date_check(uint32_t a, uint32_t b)
{
    int32_t ans;

    //@ assert is_valid_input(a, b);

    if (a <= 12 && b < 10)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else if (a <= 12 && b >= 10)
    {
        if (a < 12)
        {
            ans = 1;
            //@ assert ans == 1;
        }
        else
        {
            ans = 0;
            //@ assert ans == 0;
        }
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }

    //@ assert ans == 0 || ans == 1;
    return ans;
}

/* ====== Original function 3: range_check ====== */

/*@
    predicate is_in_range(integer n, integer a, integer b) =
        1 <= n <= 10000 && 0 <= a < b <= 1000000000;
*/

bool range_check(int n, int a, int b)
{
    long long na;
    bool result;

    //@ assert 1 <= n <= 10000;
    //@ assert 0 <= a < b <= 1000000000;

    na = (long long)n * (long long)a;

    result = na < b;
    //@ assert result == (n * a < b);

    return result;
}

/* ====== Original function 4: mod_check ====== */

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= n <= 50;
*/

int64_t mod_check(uint64_t n, uint64_t k) {
    uint64_t n_mod;
    int64_t ans;

    //@ assert valid_params(n, k);
    
    if (n % k != 0) {
        n_mod = 1;
    } else {
        n_mod = 0;
    }

    if (n_mod == 0) {
        ans = 0;
    } else {
        ans = 1;
    }

    //@ assert ans >= 0 && ans <= 1;

    return ans;
}

/* ====== Synthesized function: process_database_record ====== */

/*@
    predicate valid_record(int *data, integer data_len, integer month, integer day,
                           integer threshold_n, integer threshold_a, integer threshold_b,
                           integer mod_n, integer mod_k) =
        valid_array(data, data_len) &&
        is_valid_input(month, day) &&
        is_in_range(threshold_n, threshold_a, threshold_b) &&
        valid_params(mod_n, mod_k);
*/

int64_t process_database_record(
    size_t data_len, int *data,
    uint32_t month, uint32_t day,
    int threshold_n, int threshold_a, int threshold_b,
    uint64_t mod_n, uint64_t mod_k)
{
    size_t odd_count = count_odd_in_even_positions(data_len, data);
    //@ assert odd_count > 0 || odd_count == 0;

    int32_t date_valid = date_check(month, day);
    //@ assert date_valid == 0 || date_valid == 1;

    bool threshold_ok = range_check(threshold_n, threshold_a, threshold_b);
    //@ assert threshold_ok == (threshold_n * threshold_a < threshold_b);

    int64_t mod_result = mod_check(mod_n, mod_k);
    //@ assert mod_result >= 0 && mod_result <= 1;

    int64_t final_result;

    if (odd_count > 0 && date_valid == 1 && threshold_ok && mod_result == 1) {
        final_result = 1;
    } else {
        final_result = 0;
    }

    //@ assert final_result == 0 || final_result == 1;
    //@ assert (odd_count > 0 && date_valid == 1 && threshold_ok && mod_result == 1) ==> final_result == 1;

    return final_result;
}
