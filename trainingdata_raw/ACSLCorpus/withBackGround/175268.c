/*@
predicate greater_than(integer x, integer k) = k > x;
*/

/*@
lemma test_greater_than:
    greater_than(10, 20) &&
    !greater_than(10, 10) &&
    !greater_than(10, 5);
*/

/*@
lemma test_greater_than_all:
    \forall integer k; k > 10 ==> greater_than(10, k);
*/

int main() {
    // Variable declarations
    int __verus_tmp;
    
    // Proof logic implementation
    /*@ assert greater_than(10, 20); */
    
    /*@ assert !greater_than(10, 10); */
    
    /*@ assert !greater_than(10, 5); */
    
    return 0;
}
