#include <stdbool.h>

/* ACSL predicates from the underlying functions */
/*@
    predicate is_valid_range(integer k, integer n) =
        0 <= k && k < n && n > 0;

    predicate distinct(integer a, integer b, integer c) =
        a != b && a != c && b != c;

    predicate is_min(integer a, integer b, integer c) =
        a < b && a < c && (b < c || c < b);

    lemma assert_even_triangles_dont_overlap:
        \forall integer k, n;
        is_valid_range(k, n) ==>
        k * 2 < n * 2;
*/

/* Underlying function 1: checks if 2*k < 2*n */
void compute_comparison(int k, int n, _Bool *out) {
    _Bool result;
    //@ assert is_valid_range(k, n);
    result = (k * 2) < (n * 2);
    //@ assert result == 1;
    *out = result;
}

/* Underlying function 2: checks if a is the minimum of three distinct values */
bool func(unsigned int a, unsigned int b, unsigned int c) {
    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= c <= 100;
    //@ assert distinct(a, b, c);
    if ((a < b && a < c) && (b < c || c < b)) {
        return true;
    } else {
        return false;
    }
}

/* 
 * Synthesized function: Minimum Index Validator in a Sorted Range
 * Real-world scenario: In a sorted data structure (e.g., a priority queue or sorted array),
 * we want to verify that the smallest element (at index k) is within a valid range [0, n-1],
 * and that its value is indeed the minimum among three candidate values (a, b, c).
 * 
 * Control flow: Sequence - first validate the range property, then check the minimum property.
 * The synthesized function combines the two into a single verification of a "valid minimum index"
 * property: the element at position k satisfies both the range constraint and the minimum value constraint.
 */

bool validate_minimum_in_range(int k, int n, unsigned int a, unsigned int b, unsigned int c) {
    _Bool range_result;
    bool min_result;

    compute_comparison(k, n, &range_result);
    //@ assert range_result == 1;  // from compute_comparison postcondition

    min_result = func(a, b, c);
    //@ assert min_result == true <==> is_min(a, b, c);  // from func postcondition

    //@ assert (range_result == 1 && min_result == true) ==> (is_min(a, b, c) && (k * 2 < n * 2));
    //@ assert (range_result == 0 || min_result == false) ==> (!is_min(a, b, c) || !(k * 2 < n * 2));

    return (range_result == 1 && min_result == true);
}
