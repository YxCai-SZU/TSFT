#include <stddef.h>

/*@ predicate is_valid_range(integer r) = 1 <= r <= 100; */

/*@ logic integer compute_expected(integer r) = (r * 2 * 314) / 100; */

/*@ lemma division_property: 
      \forall integer r; 
        is_valid_range(r) ==> 
        (r * 2 * 314) / 100 == compute_expected(r); */

/*@
requires is_valid_range(r);
ensures \result == compute_expected(r);
assigns \nothing;
*/
int func(size_t r)
{
    // Variable declarations
    int pi = 314;
    int result = 0;
    size_t i = 0;
    int final_result = 0;
    int temp_result = 0;
    
    // First loop: accumulate multiplication
    /*@
    loop invariant 0 <= i <= r;
    loop invariant result == (int)(i * 2 * 314);
    loop invariant pi == 314;
    loop assigns i, result;
    loop variant r - i;
    */
    while (i < r) {
        result += 2 * pi;
        i += 1;
    }
    
    //@ assert result == (int)(r * 2 * 314);
    
    // Second loop: perform division by 100
    temp_result = result;
    /*@
    loop invariant 0 <= final_result;
    loop invariant temp_result >= 0;
    loop invariant temp_result + final_result * 100 == result;
    loop assigns final_result, temp_result;
    loop variant temp_result;
    */
    while (temp_result >= 100) {
        final_result += 1;
        temp_result -= 100;
    }
    
    //@ assert final_result == compute_expected(r);
    return final_result;
}
