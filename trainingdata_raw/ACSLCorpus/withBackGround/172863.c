#include <stdint.h>

/*@
    predicate valid_params(integer A, integer P) =
        0 <= A && A <= 100 && 0 <= P && P <= 100;

    logic integer total_sum(integer A, integer P) = A * 3 + P;

    predicate loop_invariant1(integer sum, integer A, integer P, integer count) =
        sum >= 0 && sum <= total_sum(A, P) &&
        count <= (total_sum(A, P) - sum) / 2 &&
        valid_params(A, P);

    predicate loop_invariant2(integer ceil_sum, integer A, integer P, integer ceil_count) =
        ceil_sum >= 0 && ceil_sum <= total_sum(A, P) &&
        ceil_count <= (total_sum(A, P) - ceil_sum) / 2 &&
        valid_params(A, P);

    lemma division_property:
        \forall integer A, P; valid_params(A, P) ==>
        total_sum(A, P) >= 0;

    lemma even_division:
        \forall integer s, c; s >= 0 && c <= (s - (s % 2)) / 2 ==> c * 2 <= s;
*/

/*@
    requires 0 <= A && A <= 100;
    requires 0 <= P && P <= 100;
    ensures \result <= A * 3 + P;
    ensures \result >= 0;
*/
uint32_t func(uint32_t A, uint32_t P) {
    uint32_t sum;
    uint32_t ans;
    uint32_t is_even;
    uint32_t count;
    uint32_t ceil_count;
    uint32_t ceil_sum;

    sum = A * 3 + P;
    ans = 0;
    is_even = (sum % 2 == 0);
    count = 0;

    //@ assert valid_params(A, P);
    //@ assert sum == total_sum(A, P);

    /*@
        loop invariant loop_invariant1(sum, A, P, count);
        loop assigns sum, count;
        loop variant sum;
    */
    while (sum >= 2) {
        //@ assert sum >= 2;
        sum -= 2;
        count += 1;
        //@ assert sum >= 0;
    }
    ans = count;

    if (is_even) {
        //@ assert ans <= total_sum(A, P);
        return ans;
    } else {
        ceil_count = 0;
        ceil_sum = A * 3 + P;

        /*@
            loop invariant loop_invariant2(ceil_sum, A, P, ceil_count);
            loop assigns ceil_sum, ceil_count;
            loop variant ceil_sum;
        */
        while (ceil_sum >= 2) {
            //@ assert ceil_sum >= 2;
            ceil_sum -= 2;
            ceil_count += 1;
            //@ assert ceil_sum >= 0;
        }
        //@ assert ceil_count <= total_sum(A, P);
        return ceil_count;
    }
}
