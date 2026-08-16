#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate is_odd(integer x) = x % 2 != 0;
    predicate product_is_odd(integer a, integer b) = is_odd(a * b);
*/

bool func1(int a, int b)
{
    bool a_is_odd;
    bool b_is_odd;
    bool both_odd;
    
    a_is_odd = (a % 2 != 0);
    b_is_odd = (b % 2 != 0);
    both_odd = a_is_odd && b_is_odd;
    
    //@ assert both_odd == ( (a * b) % 2 != 0 );
    
    return both_odd;
}

/*@
    predicate valid_vector(int *v, size_t len) =
        len >= 3 &&
        1 <= v[0] <= 100 &&
        1 <= v[1] <= 100 &&
        1 <= v[2] <= 100;

    logic integer vector_sum(integer a, integer b, integer c) = a + b + c;
*/

bool func2(int *v, size_t len) {
    bool result;

    //@ assert len >= 3;
    //@ assert 1 <= v[0] <= 100;
    //@ assert 1 <= v[1] <= 100;
    //@ assert 1 <= v[2] <= 100;

    result = v[1] <= v[2] && v[2] <= (v[0] + v[1] + 1);
    return result;
}

/*@ predicate is_valid_input(int64_t *input, integer len) =
    len == 2 &&
    1 <= input[0] && input[0] <= 100 &&
    1 <= input[1] && input[1] <= 100;
*/

/*@ logic integer compute_result(integer n, integer m) =
    n - 2 * m;
*/

/*@ lemma result_nonnegative:
    \forall integer n, m;
    1 <= n <= 100 && 1 <= m <= 100 ==>
    (compute_result(n, m) >= 0 ? compute_result(n, m) : 0) >= 0;
*/

/*@ lemma result_cases:
    \forall integer n, m, res;
    1 <= n <= 100 && 1 <= m <= 100 &&
    res == (compute_result(n, m) >= 0 ? compute_result(n, m) : 0) ==>
    res == compute_result(n, m) || res == 0;
*/

int64_t func3(int64_t *input)
{
    int64_t result;
    
    //@ assert is_valid_input(input, 2);
    //@ assert 1 <= input[0] && input[0] <= 100;
    //@ assert 1 <= input[1] && input[1] <= 100;
    
    result = input[0] - input[1] * 2;
    //@ assert result == compute_result(input[0], input[1]);
    
    if (result < 0)
    {
        //@ assert compute_result(input[0], input[1]) < 0;
        result = 0;
        //@ assert result == 0;
    }
    //@ assert result >= 0;
    //@ assert result == compute_result(input[0], input[1]) || result == 0;
    
    return result;
}

bool sensor_data_validator(int sensor_data[3])
{
    int64_t raw_input[2];
    raw_input[0] = (int64_t)sensor_data[0];
    raw_input[1] = (int64_t)sensor_data[1];
    
    int64_t derived = func3(raw_input);
    
    int clamped_derived;
    if (derived < 1) {
        clamped_derived = 1;
    } else if (derived > 3) {
        clamped_derived = 3;
    } else {
        clamped_derived = (int)derived;
    }
    
    bool odd_check = func1(clamped_derived, sensor_data[2]);
    
    bool monotonic_check = func2(sensor_data, 3);
    
    bool result = odd_check && monotonic_check;
    
    //@ assert result ==> monotonic_check;
    
    return result;
}
