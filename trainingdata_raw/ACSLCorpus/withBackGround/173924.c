#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    predicate pi_fixed(integer pi) = pi == 314;
    predicate temp_nonneg(integer temp) = temp >= 0;
    predicate temp_relation(integer r, integer pi, integer temp, integer count) =
        temp == 2 * r * pi - 100 * count;
    predicate count_bounds(integer r, integer pi, integer count) =
        count >= 0 && count <= (2 * r * pi) / 100;
    predicate result_eq_count(integer result, integer count) = result == count;
*/

/*@
    logic integer final_result(integer r) = (2 * r * 314) / 100;
*/

/*@
    lemma loop_decreases:
        \forall integer temp; temp >= 100 ==> temp - 100 < temp;
*/

/*@
    requires r_in_range(r);
    ensures \result == final_result(r);
*/
int func(int r)
{
    //@ assert r_in_range(r);
    int pi = 314;
    //@ assert pi_fixed(pi);
    int result = 0;
    int temp = 2 * r * pi;
    int count = 0;
    
    /*@
        loop invariant r_in_range(r);
        loop invariant pi_fixed(pi);
        loop invariant temp_nonneg(temp);
        loop invariant temp_relation(r, pi, temp, count);
        loop invariant count_bounds(r, pi, count);
        loop invariant result_eq_count(result, count);
        loop assigns result, temp, count;
        loop variant temp;
    */
    while (temp >= 100) {
        //@ assert temp >= 100;
        result += 1;
        temp -= 100;
        count += 1;
        //@ assert temp_relation(r, pi, temp, count);
    }
    //@ assert result == final_result(r);
    return result;
}
