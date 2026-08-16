/*@
    predicate bounds(integer x, integer y) = 0 <= x <= 8 && 0 <= y <= 8;
    predicate product_bound(integer x, integer y) = x * y <= 64;
*/

/*@
    requires bounds(x, y);
    ensures product_bound(x, y);
*/
void proof_by_computation_exercise(unsigned int x, unsigned int y) {
    //@ assert bounds(x, y);
    //@ assert product_bound(x, y);
}

/*@
    requires bounds(x, y);
    ensures product_bound(x, y);
*/
void additional_example(unsigned int x, unsigned int y) {
    //@ assert bounds(x, y);
    //@ assert product_bound(x, y);
}

/*@
    requires bounds(x, y);
    ensures product_bound(x, y);
*/
void more_practice(unsigned int x, unsigned int y) {
    //@ assert bounds(x, y);
    //@ assert product_bound(x, y);
}

/*@
    requires bounds(x, y);
    ensures product_bound(x, y);
*/
void even_more_practice(unsigned int x, unsigned int y) {
    //@ assert bounds(x, y);
    //@ assert product_bound(x, y);
}
