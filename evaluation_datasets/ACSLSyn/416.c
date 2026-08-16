#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *a, integer n) =
      n > 0 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
*/


/*@ lemma count_bound: \forall integer n, integer count;
      is_valid_array((int *)0, n) && 0 <= count <= n ==> count >= 0 && count <= n;
*/

int count_odd_capped(int n, int *a) {
    int count = 0;
    int x = 0;
    size_t index = 0;
    
    while (index < (size_t)n) {
        x = a[index];
        //@ assert x > 0 && x <= 1000000000;
        if ((x & 1) == 1) {
            count += 1;
        }
        index += 1;
    }
    
    int half_n = n / 2;
    //@ assert half_n >= 0 && half_n <= n;
    
    if (count <= half_n) {
        //@ assert count >= 0 && count <= n;
        return count;
    } else {
        //@ assert half_n >= 0 && half_n <= n;
        return half_n;
    }
}

/*@
    predicate is_valid_pair(integer a, integer b) =
        a != b &&
        (a == 1 || a == 2 || a == 3) &&
        (b == 1 || b == 2 || b == 3);

    logic integer missing(integer a, integer b) = 6 - a - b;

    lemma func_properties:
        \forall integer a, b;
        is_valid_pair(a, b) ==>
        (missing(a, b) == 1 || missing(a, b) == 2 || missing(a, b) == 3) &&
        missing(a, b) != a && missing(a, b) != b;
*/

int get_missing(void) {
    int result;

    //@ assert is_valid_pair(1, 2);
    //@ assert missing(1, 2) == 3;
    result = 6 - 1 - 2;

    //@ assert result == 3;
    return result;
}

/*@
    predicate is_power_of_ten(integer x) =
        x == 1 || x == 10 || x == 100 || x == 1000 || x == 10000;
 */

size_t floor_power_of_ten(size_t n)
{
    size_t result;
    result = 1;

    if (n >= 10000)
    {
        result = 10000;
    }
    else if (n >= 1000)
    {
        result = 1000;
    }
    else if (n >= 100)
    {
        result = 100;
    }
    else if (n >= 10)
    {
        result = 10;
    }

    //@ assert is_power_of_ten(result);
    return result;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

size_t compute_bound(size_t a, size_t b) {
    size_t ans = 0;
    size_t tmp = 0;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    if (a > b) {
        ans += b;
        tmp = a - b - 1;
        ans += tmp / 3;
        //@ assert ans <= a + b + 1;
    } else {
        ans += a;
        //@ assert ans <= a + b + 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}

size_t process_data_stream(int n, int *a) {
    int capped_count = count_odd_capped(n, a);
    //@ assert capped_count >= 0 && capped_count <= n;

    size_t pow10 = floor_power_of_ten((size_t)n);
    //@ assert is_power_of_ten(pow10);
    //@ assert pow10 >= 1 && pow10 <= (size_t)n;

    int missing_val = get_missing();
    //@ assert missing_val == 3;

    size_t input_a, input_b;
    if (capped_count < 1) {
        input_a = 1;
    } else if (capped_count > 100) {
        input_a = 100;
    } else {
        input_a = (size_t)capped_count;
    }
    
    if (pow10 < 1) {
        input_b = 1;
    } else if (pow10 > 100) {
        input_b = 100;
    } else {
        input_b = pow10;
    }
    
    //@ assert valid_range(input_a) && valid_range(input_b);
    
    size_t bound_result = compute_bound(input_a, input_b);
    //@ assert bound_result >= 0;
    //@ assert bound_result <= input_a + input_b + 1;

    size_t final_result = (size_t)capped_count + bound_result;
    
    //@ assert final_result >= 0;
    //@ assert final_result <= n + 100 + 100 + 1;
    
    return final_result;
}
