#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;

    logic integer square(integer n) = n * n;

    lemma square_bounds:
        \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;

    lemma abs_nonnegative:
        \forall integer x; x >= 0 ==> (x < 0 ? -x : x) == x;

    lemma max_ge_min:
        \forall integer x, y; (x > y ? x : y) >= (x < y ? x : y);
        
    predicate valid_range(integer n) = 1 <= n <= 100;
    
    logic integer division_by_15(integer n) = n / 15;
    
    logic integer expected_result(integer n) = n * 800 - division_by_15(n) * 200;
    
    // Combined predicate: result is positive and represents valid price after discount
    predicate valid_price(integer price) = price >= 0;
*/

int64_t func(int64_t n, int64_t a)
{
    int64_t nn;
    int64_t a_abs;
    int64_t max_value;
    int64_t min_value;
    int64_t result;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;

    //@ assert n * n <= 10000;
    nn = n * n;

    a_abs = a < 0 ? -a : a;

    max_value = nn > a_abs ? nn : a_abs;
    min_value = nn < a_abs ? nn : a_abs;

    //@ assert max_value == nn || max_value == a_abs;
    //@ assert min_value == nn || min_value == a_abs;
    //@ assert max_value >= min_value;

    result = nn - a_abs;
    //@ assert result == n * n - (a < 0 ? -a : a);
    return result;
}

int64_t func2(int64_t n)
{
    int64_t n_div_15;
    int64_t temp_n;
    int64_t count;
    
    n_div_15 = 0;
    temp_n = n;
    count = 0;
    
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        count += 1;
    }
    
    n_div_15 = count;
    
    //@ assert n_div_15 == division_by_15(n);
    //@ assert n * 800 - n_div_15 * 200 == expected_result(n);
    
    return n * 800 - n_div_15 * 200;
}

int64_t compute_inventory_value(int64_t n, int64_t a)
{
    
    int64_t remaining_stock;
    int64_t discount_savings;
    int64_t total_value;
    
    remaining_stock = func(n, a);
    //@ assert remaining_stock == n * n - (a < 0 ? -a : a);
    
    discount_savings = func2(n);
    //@ assert discount_savings == expected_result(n);
    
    total_value = remaining_stock + discount_savings;
    
    //@ assert total_value == (n * n - (a < 0 ? -a : a)) + expected_result(n);
    //@ assert total_value >= 0;  // Valid price property
    //@ assert valid_price(total_value);
    
    return total_value;
}
