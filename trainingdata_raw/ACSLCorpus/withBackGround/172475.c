/*@
    predicate is_in_range(integer y) = 1 <= y && y <= 9;
    predicate square_in_range(integer y) = 1 <= y*y && y*y <= 81;
    
    lemma square_bound: \forall integer y; is_in_range(y) ==> square_in_range(y);
*/

/*@
    requires 1 <= y && y <= 9;
    ensures 1 <= y*y && y*y <= 81;
*/
void structuring_nested_quantifiersProof(int y) {
    // Variable declarations at top of scope
    int y_squared;
    
    //@ assert 1 <= y && y <= 9;
    
    y_squared = y * y;
    
    //@ assert 1 <= y_squared && y_squared <= 81;
}
