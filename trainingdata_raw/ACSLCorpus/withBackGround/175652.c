/*@
    predicate bounds(integer x, integer y, integer z) =
        0 <= x && x <= 100 && 0 <= y && y <= 100 && 0 <= z && z <= 100;

    lemma nonlinear_product_bound:
        \forall integer x, y;
        bounds(x, y, 0) ==> x * y <= 10000;

    lemma nonlinear_distributive:
        \forall integer x, y, z;
        bounds(x, y, z) ==> x * (y + z) == x * y + x * z;

    lemma nonlinear_product_nonneg:
        \forall integer x, y;
        bounds(x, y, 0) ==> 0 <= x * y;

    lemma nonlinear_sum_bound:
        \forall integer x, y, z;
        bounds(x, y, z) ==> 0 <= x * (y + z) && x * (y + z) <= 20000;
*/

/*@
    requires 0 <= x && x <= 100 && 0 <= y && y <= 100 && 0 <= z && z <= 100;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_nonlinear_arith(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * y <= 10000;
    //@ assert x * (y + z) == x * y + x * z;
    //@ assert 0 <= x * y;
    //@ assert 0 <= x * (y + z) && x * (y + z) <= 20000;
    return 0;
}

/*@
    assigns \nothing;
*/
int main() {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    
    x = 0;
    y = 0;
    z = 0;
    
    //@ assert bounds(x, y, z);
    verify_nonlinear_arith(x, y, z);
    return 0;
}
