#include <stdbool.h>
#include <stddef.h>

/* ===== Original functions with their specifications ===== */

/*@
    predicate condition1(integer a, integer b, integer c, integer d) =
        (c - b == b - a) && (d >= c - b);
    predicate condition2(integer a, integer b, integer c, integer d) =
        (b - a == d) && (d <= c - b);
    predicate final_condition(integer a, integer b, integer c, integer d) =
        condition1(a, b, c, d) || condition2(a, b, c, d);
*/

bool func1(int a, int b, int c, int d)
{
    bool result;
    int diff_cb;
    int diff_ba;
    int diff_cb_ba;
    int diff_ba_d;

    diff_cb = c - b;
    diff_ba = b - a;
    diff_cb_ba = diff_cb == diff_ba;
    diff_ba_d = diff_ba == d;

    //@ assert diff_cb_ba == (c - b == b - a);
    //@ assert diff_ba_d == (b - a == d);

    if ((diff_cb_ba && (d >= diff_cb)) || (diff_ba_d && (d <= diff_cb)))
    {
        result = true;
        //@ assert final_condition(a, b, c, d);
    }
    else
    {
        result = false;
        //@ assert !final_condition(a, b, c, d);
    }

    return result;
}

/*@
    predicate ac_condition(integer m, integer n) =
        (n - m) <= 2 * m;
*/

bool is_ac(int m, int n) {
    bool is_ac_var = false;
    
    //@ assert ac_condition(m, n) ==> (n - m) <= 2 * m;
    if ((n - m) <= 2 * m) {
        is_ac_var = true;
    }
    
    //@ assert is_ac_var == true <==> ac_condition(m, n);
    return is_ac_var;
}

/*@ predicate all_even_in_range{L}(size_t *an, integer i) =
      \forall integer j; 0 <= j < i ==> an[j] % 2 == 0;
*/

bool func3(size_t n, const size_t an[]) {
    bool all_even = true;
    size_t i = 0;

    while (i < n) {
        //@ assert 0 <= i < n;
        if (an[i] % 2 != 0) {
            all_even = false;
            //@ assert all_even == false;
            break;
        }
        i++;
    }
    return all_even;
}

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (a > c && a - c >= d) ||
        (b > d && b - d >= a) ||
        (a <= c && a + b >= c + d);
*/

bool func4(int a, int b, int c, int d)
{
    bool result;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    
    if ((a > c && a - c >= d) || (b > d && b - d >= a) || (a <= c && a + b >= c + d)) {
        result = true;
        //@ assert condition_holds(a, b, c, d);
    } else {
        result = false;
        //@ assert !condition_holds(a, b, c, d);
    }
    
    return result;
}

/* ===== Synthesized complex function: Data Validation Pipeline ===== */

/*@
    predicate valid_data_pipeline(integer a, integer b, integer c, integer d, 
                                  integer m, integer n, integer k, size_t *arr) =
        (final_condition(a, b, c, d) && 
         ac_condition(m, n) &&
         (\forall integer i; 0 <= i < k ==> arr[i] % 2 == 0) &&
         condition_holds(a, b, c, d));
*/

bool process_data(int a, int b, int c, int d, int m, int n, size_t k, const size_t arr[]) {
    bool step1_result = func1(a, b, c, d);
    bool step2_result = is_ac(m, n);
    bool step3_result = func3(k, arr);
    bool step4_result = func4(a, b, c, d);
    
    bool pipeline_result = step1_result && step2_result && step3_result && step4_result;
    
    //@ assert pipeline_result == true ==> (final_condition(a, b, c, d) && ac_condition(m, n) && (\forall integer i; 0 <= i < k ==> arr[i] % 2 == 0) && condition_holds(a, b, c, d));
    
    return pipeline_result;
}
