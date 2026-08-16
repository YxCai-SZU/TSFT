#include <stdbool.h>

/*@
    predicate is_valid_vector(int *v, integer len) =
        len == 2 &&
        1 <= v[0] <= 100 &&
        0 <= v[1] <= 4111;

    logic integer compute_result(integer i) = i * 500;

    lemma result_monotonic:
        \forall integer i, j; i <= j ==> compute_result(i) <= compute_result(j);
*/

/*@
    requires \valid(v + (0..1));
    requires is_valid_vector(v, 2);
    ensures \result == (v[0] * 500 >= v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    int result = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= v[0];
        loop invariant result == compute_result(i);
        loop invariant is_valid_vector(v, 2);
        loop assigns result, i;
        loop variant v[0] - i;
    */
    while (i < v[0]) {
        //@ assert result == i * 500;
        result += 500;
        i += 1;
        //@ assert result == i * 500;
    }
    
    //@ assert result == v[0] * 500;
    return result >= v[1];
}
