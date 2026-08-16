#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    lemma bounds_after_increment:
        \forall integer a, b, c;
            1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 ==>
            1 <= a + 1 <= 101 && 1 <= b + 1 <= 101 && 1 <= c + 1 <= 101;
*/

bool check_ordered_incremented(int a, int b, int c)
{
    int a_inc, b_inc, c_inc;
    bool result;

    a_inc = a + 1;
    b_inc = b + 1;
    c_inc = c + 1;

    //@ assert 1 <= a_inc <= 101;
    //@ assert 1 <= b_inc <= 101;
    //@ assert 1 <= c_inc <= 101;

    if (a_inc < b_inc && b_inc < c_inc)
    {
        //@ assert is_ordered(a_inc, b_inc, c_inc);
        result = true;
    }
    else
    {
        //@ assert !is_ordered(a_inc, b_inc, c_inc);
        result = false;
    }

    return result;
}

/*@ predicate all_le_before(integer idx, integer m, int *arr, integer n) =
      \forall integer i; 0 <= i < idx ==> arr[i] <= m;
*/

/*@ lemma loop_conclusion:
      \forall integer n, integer m, int *arr;
      (\forall integer i; 0 <= i < n ==> arr[i] <= m) ==>
      all_le_before(n, m, arr, n);
*/

bool check_all_below_limit(size_t n, size_t m, int *numbers) {
    bool ok = true;
    size_t index = 0;

    while (index < n) {
        int a = numbers[index];
        if (a > m) {
            ok = false;
        }
        index++;
    }

    //@ assert ok == true <==> all_le_before(n, m, numbers, n);
    return ok;
}

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;
*/

bool check_sufficient_capacity(int d, int t, int s)
{
    bool result;

    //@ assert 1 <= t * s <= 10000 * 10000;
    
    if (t * s < d)
    {
        result = false;
    }
    else
    {
        result = true;
    }
    
    //@ assert result == true <==> (t * s >= d);
    return result;
}

/*@
    predicate allocation_valid(int r1, int r2, int r3, size_t limit, size_t n, int *requests, int d, int t, int s) =
        is_ordered(r1, r2, r3) &&
        \forall integer i; 0 <= i < n ==> requests[i] <= limit &&
        (t * s >= d);
*/

bool validate_resource_allocation(int r1, int r2, int r3, size_t limit, size_t n, int *requests, int d, int t, int s)
{
    bool order_ok;
    bool limit_ok;
    bool capacity_ok;
    bool final_result;

    order_ok = check_ordered_incremented(r1, r2, r3);

    limit_ok = check_all_below_limit(n, limit, requests);

    capacity_ok = check_sufficient_capacity(d, t, s);

    final_result = order_ok && limit_ok && capacity_ok;

    return final_result;
}
