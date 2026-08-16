/*@
    predicate bounds(integer x, integer y) =
        0 <= x && x <= y && y <= 100;

    lemma nonlinear_arithmetic_example_1:
        \forall integer x, y; bounds(x, y) ==> x * y <= 10000;

    lemma nonlinear_arithmetic_example_2:
        \forall integer x, y; bounds(x, y) ==> x * y <= 10000;

    lemma nonlinear_arithmetic_example_3:
        \forall integer x, y; bounds(x, y) ==> x * y <= 10000;

    lemma nonlinear_arithmetic_example_4:
        \forall integer x, y; bounds(x, y) ==> x * y <= 10000;

    lemma nonlinear_arithmetic_example_5:
        \forall integer x, y; bounds(x, y) ==> x * y <= 10000;
*/

/*@
    requires 0 <= x && x <= y && y <= 100;
    ensures \result <= 10000;
    assigns \nothing;
*/
int verify_nonlinear_product(int x, int y) {
    int product;
    
    product = x * y;
    
    //@ assert product <= 10000;
    
    return product;
}

int main() {
    return 0;
}
