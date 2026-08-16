#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate within_range(integer x) = 1 <= x <= 100;
    predicate result_condition(integer a, integer b, bool result) =
        result == (b % 2 == 0 && a <= 6);
*/

bool func1(unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert within_range(a);
    
    if (b % 2 == 0) {
        //@ assert b % 2 == 0;
        result = (a <= 6);
    } else {
        //@ assert b % 2 != 0;
        result = false;
    }
    
    //@ assert result == (b % 2 == 0 && a <= 6);
    return result;
}

/*@ predicate valid_params(integer n, int *w) =
    n >= 2 && n <= 100 &&
    \valid(w + (0 .. n-1)) &&
    \forall integer k; 0 <= k < n ==> w[k] >= 1 && w[k] <= 100;
*/

/*@ predicate sum_bounds(integer i, integer s) =
    s >= 0 && s <= i * 100;
*/

int func2(int n, int *w) {
    int s = 0;
    int i = 0;
    int min = INT_MAX;
    int l, r, j;
    int diff;
    
    while (i < n) {
        //@ assert w[i] >= 1 && w[i] <= 100;
        s += w[i];
        i++;
    }
    
    i = 0;
    while (i < n) {
        l = 0;
        j = 0;
        while (j <= i) {
            //@ assert w[j] >= 1 && w[j] <= 100;
            l += w[j];
            j++;
        }
        
        r = 0;
        j = i + 1;
        while (j < n) {
            //@ assert w[j] >= 1 && w[j] <= 100;
            r += w[j];
            j++;
        }
        
        diff = l - r;
        if (diff < 0) diff = -diff;
        if (diff < min) min = diff;
        i++;
    }
    return min;
}

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_within_100(integer x) = 0 <= x <= 100;
    predicate is_within_200(integer x) = 0 <= x <= 200;
*/

/*@
    logic integer min_val(integer a, integer b) = (a < b) ? a : b;
*/

/*@
    lemma subtraction_preserves_nonnegativity:
        \forall integer a, b;
            is_within_100(a) && is_within_100(b) && min_val(a, b) <= a ==>
                a - min_val(a, b) >= 0;
*/

/*@
    lemma sum_bound:
        \forall integer a, b;
            is_within_100(a) && is_within_100(b) ==>
                a + b <= 200;
*/

int64_t func3(int64_t a, int64_t b, int64_t c)
{
    int64_t result = 0;
    int64_t min_val;
    int64_t a_local;
    int64_t b_local;

    //@ assert is_within_100(a) && is_within_100(b) && is_within_100(c);

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    //@ assert min_val == min_val(a, b);

    result += min_val;
    //@ assert result == min_val(a, b);

    a_local = a - min_val;
    b_local = b - min_val;
    //@ assert is_nonnegative(a_local) && is_nonnegative(b_local);

    //@ assert a_local + b_local <= 200;
    //@ assert c <= 100;

    if (c > a_local + b_local) {
        result += a_local + b_local;
    } else {
        result += c;
    }
    //@ assert result <= 200;

    //@ assert is_nonnegative(result);
    return result;
}

/*@
    predicate load_balancer_valid(integer a, integer b, integer n, int *w, integer c, integer result) =
        1 <= a <= 100 && 1 <= b <= 100 &&
        valid_params(n, w) &&
        0 <= c <= 100 &&
        0 <= result <= 200;
*/

int64_t load_balancer(unsigned int a, unsigned int b, int n, int *w, int64_t c)
{
    bool eligible;
    int min_diff;
    int64_t allocation;
    
    eligible = func1(a, b);
    
    if (eligible) {
        min_diff = func2(n, w);
        //@ assert min_diff >= 0;
        
        int64_t param1 = (int64_t)a;  // 1..100
        int64_t param2 = (int64_t)(min_diff % 100);  // 0..99
        int64_t param3 = c;  // 0..100
        
        //@ assert is_within_100(param1) && is_within_100(param2) && is_within_100(param3);
        
        allocation = func3(param1, param2, param3);
        //@ assert is_nonnegative(allocation) && is_within_200(allocation);
    } else {
        allocation = c;
        //@ assert is_within_100(allocation);
    }
    
    //@ assert 0 <= allocation <= 200;
    return allocation;
}
