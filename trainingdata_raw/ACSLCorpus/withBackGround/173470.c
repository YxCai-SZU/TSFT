#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n && n <= 2095;

    logic integer triangular_num(integer n) = n * (n + 1) / 2;

    lemma overflow_bound: \forall integer n; is_valid_n(n) ==> n + 1 <= 2096;
    lemma product_bound: \forall integer n; is_valid_n(n) ==> n * (n + 1) <= 2095 * 2096;
    lemma result_bound: \forall integer n; is_valid_n(n) ==> triangular_num(n) <= triangular_num(2095);
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_num(n);
    ensures \result <= triangular_num(2095);
*/
uint32_t find_triangular_num(uint32_t n) {
    //@ assert n + 1 <= 2096;
    //@ assert n * (n + 1) <= 2095 * 2096;
    return n * (n + 1) / 2;
}
