#include <stdbool.h>

/*@ predicate vector_len_eq_two(int *v) = \valid(v) && \valid(v+1);
    predicate vector_in_range(int *v) = \valid(v) && \valid(v+1) &&
                                        v[0] >= 1 && v[0] <= 100 &&
                                        v[1] >= 1 && v[1] <= 100;
    predicate elements_equal(int *v) = \valid(v) && \valid(v+1) && v[0] == v[1];
 */

/*@ requires vector_len_eq_two(v) && vector_in_range(v);
    ensures \result == true <==> elements_equal(v);
    assigns \nothing;
 */
bool func(int *v)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert vector_len_eq_two(v);
    //@ assert vector_in_range(v);
    
    if (v[0] == v[1]) {
        //@ assert elements_equal(v);
        result = true;
    } else {
        //@ assert !elements_equal(v);
        result = false;
    }
    
    return result;
}
