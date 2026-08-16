#include <stdbool.h>
#include <stdint.h>

/* Function 1: Compute adjusted difference with bounds */
/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        c - (a - b);

    lemma result_properties:
        \forall integer a, b, c;
        bounds(a, b, c) ==>
        (compute_result(a, b, c) >= 0 ==> compute_result(a, b, c) <= c) &&
        (compute_result(a, b, c) < 0 ==> compute_result(a, b, c) <= 0);
*/

int func1(int a, int b, int c)
{
    int result;
    
    //@ assert bounds(a, b, c);
    
    result = c - (a - b);
    
    if (result > 0)
    {
        //@ assert result == compute_result(a, b, c);
        //@ assert result <= c;
        return result;
    }
    else
    {
        //@ assert result <= 0;
        result = 0;
        return result;
    }
}

/* Function 2: Safe subtraction with array */
/*@
    predicate valid_range(integer x) = -100 <= x <= 100;
    predicate valid_array(int *a) = \valid(a) && \valid(a+1) &&
                                    valid_range(a[0]) && valid_range(a[1]);
    logic integer safe_sub(integer x, integer y) = x - y;
    lemma sub_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> -200 <= safe_sub(x,y) <= 200;
*/

int func2(int *a) {
    int result;
    
    //@ assert valid_range(a[0]);
    //@ assert valid_range(a[1]);
    //@ assert -200 <= a[0] - a[1] <= 200;
    
    result = a[0] - a[1];
    
    if (a[0] > a[1]) {
        result = a[0] - a[1];
    } else {
        result = a[0] - a[1];
    }
    
    return result;
}

/* Function 3: Adjust value by category */
/*@
    predicate is_valid_x(integer x) = 0 <= x && x <= 1000000000;
    
    logic integer func_result(integer x, integer n) = x - n;
    
    lemma n_bounds:
        \forall integer x, n;
        is_valid_x(x) &&
        (x < 2 ==> n == 0) &&
        (x >= 2 && x < 5 ==> n == 1) &&
        (x >= 5 && x < 8 ==> n == 2) &&
        (x >= 8 ==> n == 3) ==>
        0 <= n && n <= 3;
*/

int32_t func3(int32_t x)
{
    int32_t n;
    
    //@ assert is_valid_x(x);
    
    if (x < 2) {
        n = 0;
    } else if (x < 5) {
        n = 1;
    } else if (x < 8) {
        n = 2;
    } else {
        n = 3;
    }
    
    //@ assert 0 <= n && n <= 3;
    
    return x - n;
}

/* Function 4: Check if k is within range of product */
/*@
    predicate is_valid_range(integer n, integer m) =
        1 <= n <= 1000 && 1 <= m <= 1000;

    logic integer product(integer n, integer m) = n * m;

    predicate matches_condition(integer n, integer m, integer k, bool ok) =
        ok == (k == product(n, m) ||
               k == product(n, m) - 1 ||
               k == product(n, m) - 2 ||
               k == product(n, m) - 3 ||
               k == product(n, m) - 4 ||
               k == product(n, m) - 5);
*/

bool func4(int n, int m, int k)
{
    bool ok;
    long long product_nm;

    //@ assert 1 <= n <= 1000;
    //@ assert 1 <= m <= 1000;
    //@ assert 0 <= k <= n * m;

    product_nm = (long long)n * (long long)m;
    //@ assert product_nm == n * m;
    //@ assert product_nm <= 1000000;

    ok = (k == product_nm);
    
    if (k == product_nm - 1) {
        ok = true;
    } else if (k == product_nm - 2) {
        ok = true;
    } else if (k == product_nm - 3) {
        ok = true;
    } else if (k == product_nm - 4) {
        ok = true;
    } else if (k == product_nm - 5) {
        ok = true;
    }

    //@ assert ok == (k == product_nm || k == product_nm - 1 || k == product_nm - 2 || k == product_nm - 3 || k == product_nm - 4 || k == product_nm - 5);

    return ok;
}

/* Synthesized function: Product inventory validation system */
/* Context: A warehouse management system validates product batches. 
   Each batch has a size (a), used items (b), and capacity (c). 
   The system checks if the adjusted capacity matches expected patterns 
   after applying category-based adjustments and array-based safety checks. */

/*@
    predicate valid_inventory(integer a, integer b, integer c, int *arr, integer x, integer n, integer m, integer k) =
        bounds(a, b, c) && valid_array(arr) && is_valid_x(x) && is_valid_range(n, m) &&
        0 <= k <= n * m;

    predicate inventory_ok(integer a, integer b, integer c, int *arr, integer x, integer n, integer m, integer k) =
        (c - (a - b) >= 0 ? c - (a - b) : 0) >= 0 &&
        (c - (a - b) >= 0 ? c - (a - b) : 0) <= c &&
        (k == n * m || k == n * m - 1 || k == n * m - 2 || k == n * m - 3 || k == n * m - 4 || k == n * m - 5);
*/

bool process_inventory(int a, int b, int c, int *arr, int32_t x, int n, int m, int k)
{
    int adj_capacity;
    int safety_diff;
    int32_t cat_adjusted;
    bool product_check;
    
    adj_capacity = func1(a, b, c);
    //@ assert adj_capacity >= 0 && adj_capacity <= c;
    
    safety_diff = func2(arr);
    //@ assert -200 <= safety_diff <= 200;
    
    cat_adjusted = func3(x);
    //@ assert cat_adjusted >= 0 && cat_adjusted <= x;
    
    product_check = func4(n, m, k);
    //@ assert product_check == (k == n*m || k == n*m - 1 || k == n*m - 2 || k == n*m - 3 || k == n*m - 4 || k == n*m - 5);
    
    //@ assert (adj_capacity >= 0 && adj_capacity <= c && safety_diff >= -200 && safety_diff <= 200 && cat_adjusted >= 0 && cat_adjusted <= x && product_check) ==> (adj_capacity >= 0 && adj_capacity <= c && (k == n*m || k == n*m - 1 || k == n*m - 2 || k == n*m - 3 || k == n*m - 4 || k == n*m - 5));
    
    return adj_capacity >= 0 && adj_capacity <= c && 
           safety_diff >= -200 && safety_diff <= 200 && 
           cat_adjusted >= 0 && cat_adjusted <= x && 
           product_check;
}
