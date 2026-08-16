#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_vector(int *v) =
        \valid(v + (0..5)) &&
        v[0] >= 0 && v[1] >= 0 && v[2] >= 0 && v[3] >= 0 && v[4] >= 0 && v[5] >= 0 &&
        v[0] <= 123 && v[1] <= 123 && v[2] <= 123 && v[3] <= 123 && v[4] <= 123 && v[5] <= 123 &&
        v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4] && v[4] < v[5];
*/

bool func1(int *v)
{
    int new_v[6];
    int i;

    i = 0;
    while (i < 6)
    {
        new_v[i] = v[i];
        i = i + 1;
    }

    //@ assert new_v[4] - new_v[0] <= new_v[5] == (v[4] - v[0] <= v[5]);
    return new_v[4] - new_v[0] <= new_v[5];
}

/*@
    predicate in_range(integer v) = 0 <= v <= 1000000000000000000;

    logic integer diff_mod(integer x, integer y) = (y - 2 * x) % 2;

    lemma diff_mod_prop:
        \forall integer x, y, d;
            in_range(x) && in_range(y) && d == y - 2 * x ==>
            d % 2 == diff_mod(x, y);
*/

bool func2(long long x, long long y) {
    int is_valid;
    long long diff;

    is_valid = 0;

    //@ assert in_range(x) && in_range(y);
    if (y >= 2 * x && y <= 4 * x) {
        diff = y - 2 * x;

        while (diff >= 2) {
            //@ assert diff >= 2;
            diff -= 2;
            //@ assert diff >= 0;
        }

        //@ assert diff == 0 ==> diff_mod(x, y) == 0;
        if (diff == 0) {
            is_valid = 1;
        }
    }

    //@ assert is_valid == (y >= 2 * x && y <= 4 * x && (y - 2 * x) % 2 == 0);
    return is_valid;
}

/*@
    predicate x_in_range(integer x) = 1 <= x && x <= 100;
    predicate y_in_range(integer y) = 1 <= y && y <= 100;
    
    logic integer compute_result(integer x, integer y) =
        (x - y * 2) > 0 ? (x - y * 2) : 0;
    
    lemma result_nonnegative:
        \forall integer x, y;
        x_in_range(x) && y_in_range(y) ==> compute_result(x, y) >= 0;
    
    lemma result_cases:
        \forall integer x, y;
        x_in_range(x) && y_in_range(y) ==> 
        compute_result(x, y) == (x - y * 2) || compute_result(x, y) == 0;
*/

int64_t func3(int64_t x, int64_t y)
{
    int64_t x_local;
    int64_t y_local;
    int64_t result;
    
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    
    x_local = x < 0 ? 0 : x;
    y_local = y < 0 ? 0 : y;
    
    //@ assert 1 <= x_local && x_local <= 100;
    //@ assert 1 <= y_local && y_local <= 100;
    
    //@ assert x_local - y_local * 2 <= 100 - 2;
    
    result = (x_local - y_local * 2) > 0 ? (x_local - y_local * 2) : 0;
    
    //@ assert result >= 0;
    //@ assert result == (x_local - y_local * 2) || result == 0;
    
    return result;
}

int64_t process_routing_update(int *v, int64_t x, int64_t y)
{
    bool constraint_satisfied;
    int is_valid_hop;
    int64_t metric_adjustment;
    
    constraint_satisfied = func1(v);
    
    is_valid_hop = func2((long long)x, (long long)y);
    
    if (constraint_satisfied && is_valid_hop) {
        metric_adjustment = func3(x, y);
    } else {
        metric_adjustment = 0;
    }
    
    //@ assert metric_adjustment >= 0;
    //@ assert metric_adjustment == (x - y * 2) || metric_adjustment == 0;
    
    return metric_adjustment;
}
