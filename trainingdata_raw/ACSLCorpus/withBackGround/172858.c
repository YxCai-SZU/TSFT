/*@
    predicate bounds_positive(integer x, integer y) =
        0 < x && x <= 10 && 0 < y && y <= 10;
    
    predicate bounds_nonnegative(integer x, integer y) =
        0 <= x && x <= 10 && 0 <= y && y <= 10;
    
    predicate bounds_one(integer x, integer y) =
        1 <= x && x <= 10 && 1 <= y && y <= 10;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma non_linear_arith_example:
        \forall integer x, y; bounds_positive(x, y) ==> product(x, y) <= 100;
    
    lemma non_linear_arith_example2:
        \forall integer x, y; bounds_nonnegative(x, y) ==> product(x, y) <= 100;
    
    lemma non_linear_arith_example3:
        \forall integer x, y; bounds_one(x, y) ==> product(x, y) <= 100;
*/

/*@
    requires 0 < x && x <= 10 && 0 < y && y <= 10;
    ensures \result == x * y;
    assigns \nothing;
*/
int compute_product(int x, int y) {
    return x * y;
}

void main() {
    // Declarations
    int x = 5;
    int y = 5;
    int result;
    
    // Example 1 verification
    //@ assert bounds_positive(x, y);
    result = compute_product(x, y);
    //@ assert result <= 100;
    
    // Example 2 verification  
    //@ assert bounds_nonnegative(x, y);
    //@ assert product(x, y) <= 100;
    
    // Example 3 verification
    //@ assert bounds_one(x, y);
    //@ assert product(x, y) <= 100;
}
