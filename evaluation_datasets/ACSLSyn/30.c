#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

/* ============================================================
   Original func: compute (c - a + b) with bounds
   ============================================================ */

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (c - a + b > 0) ? (c - a + b) : 0;

    lemma result_bounds:
        \forall integer a, b, c;
        valid_range(a, b, c) ==> 
            0 <= compute_result(a, b, c) && compute_result(a, b, c) <= c;
*/

int func_int(int a, int b, int c)
{
    int result;
    
    //@ assert 1 <= b && b <= a && a <= 20;
    
    if (c - a + b > 0)
    {
        result = c - a + b;
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    }
    else
    {
        result = 0;
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    }
}

/* ============================================================
   Original func: find index of minimum value in array of 5 elements
   ============================================================ */

/*@
    predicate valid_index(integer i, integer len) = 0 <= i < len;
    predicate valid_value(integer v) = 0 <= v <= 1000000000;
    predicate valid_array(int64_t *arr, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> valid_value(arr[i]);
*/

int64_t func_arr(int64_t v[5])
{
    int64_t min = INT64_MAX;
    int64_t min_index = 0;
    size_t i = 0;
    
    while (i < 5)
    {
        int64_t l = v[i];
        //@ assert valid_value(l);
        if (l < min)
        {
            min = l;
            min_index = (int64_t)i;
        }
        i += 1;
    }
    return min_index;
}

/* ============================================================
   Synthesized function: update array element using func result,
   then find minimum index of the updated array.
   ============================================================ */

int64_t synthesize(int a, int b, int c, int64_t v[5])
{
    int delta = func_int(a, b, c);
    //@ assert 0 <= delta && delta <= c;
    
    v[c] = delta;
    //@ assert valid_value(v[c]);
    
    int64_t min_index = func_arr(v);
    //@ assert 0 <= min_index && min_index < 5;
    
    return min_index;
}
