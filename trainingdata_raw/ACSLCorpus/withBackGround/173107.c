/*@
    predicate bounds_1_10(integer x) = 1 <= x && x <= 10;

    lemma mul_bounds_100:
        \forall integer a, b;
            bounds_1_10(a) && bounds_1_10(b) ==> 1 <= a * b && a * b <= 100;

    lemma mul_bounds_1000:
        \forall integer a, b, c;
            bounds_1_10(a) && bounds_1_10(b) && bounds_1_10(c) ==> 
            1 <= a * b * c && a * b * c <= 1000;

    lemma mul_assoc_proof:
        \forall integer a, b, c;
            bounds_1_10(a) && bounds_1_10(b) && bounds_1_10(c) ==> 
            (a * b) * c == a * (b * c);
*/

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    requires 1 <= c && c <= 10;
    ensures (a * b) * c == a * (b * c);
*/
void nonlinear_arithmetic_example_9(int a, int b, int c) {
    // Variable declarations at top
    int ab_product;
    int bc_product;
    int left_product;
    int right_product;

    // Precondition assertions
    //@ assert bounds_1_10(a);
    //@ assert bounds_1_10(b);
    //@ assert bounds_1_10(c);

    // Calculate intermediate products
    ab_product = a * b;
    bc_product = b * c;
    
    //@ assert 1 <= ab_product && ab_product <= 100;
    //@ assert 1 <= bc_product && bc_product <= 100;

    // Calculate final products
    left_product = ab_product * c;
    right_product = a * bc_product;
    
    //@ assert 1 <= left_product && left_product <= 1000;
    //@ assert 1 <= right_product && right_product <= 1000;

    // Final associative property
    //@ assert left_product == right_product;
}

int main() {
    return 0;
}
