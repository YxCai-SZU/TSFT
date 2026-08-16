#include <stdint.h>
/*@
    predicate valid_inputs(integer n, integer a) =
        1 <= n && n <= 100 &&
        0 <= a && a <= n * n;

    logic integer total_area(integer n) = n * n;

    logic integer plantable_trees(integer n, integer a) =
        total_area(n) - a;

    lemma total_area_bound: \forall integer n; 1 <= n && n <= 100 ==> total_area(n) <= 10000;
    lemma subtraction_safe: \forall integer n, a; valid_inputs(n, a) ==> total_area(n) >= a;
    lemma result_correct: \forall integer n, a; valid_inputs(n, a) ==> 
        plantable_trees(n, a) == total_area(n) - a;
*/

/*@
    requires valid_inputs(n, a);
    ensures \result == plantable_trees(n, a);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a) {
    uint64_t total_area;
    uint64_t plantable_trees;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    
    // Calculate the area of the forest
    //@ assert total_area(n) <= 10000;
    total_area = n * n;

    // Add an assertion to ensure no underflow/overflow occurs in the subtraction
    //@ assert total_area >= a;

    // Calculate the number of trees that can be planted
    plantable_trees = total_area - a;

    // Add an assertion to ensure no underflow/overflow occurs in the subtraction
    //@ assert plantable_trees <= total_area;

    return plantable_trees;
}
