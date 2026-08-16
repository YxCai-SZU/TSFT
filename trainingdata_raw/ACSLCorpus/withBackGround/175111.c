/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer product(integer a, integer b) = a * b;

    predicate product_in_range(integer a, integer b) =
        bounds(a, b) ==> 1 <= product(a, b) <= 100000000;

    lemma product_range: \forall integer a, b; bounds(a, b) ==> product_in_range(a, b);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 == 0);
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int product;
    int is_even;
    int abs_product;

    //@ assert bounds(a, b);
    //@ assert product_in_range(a, b);
    
    product = a * b;
    is_even = 0;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }

    /*@
        loop invariant 0 <= abs_product <= 100000000;
        loop invariant bounds(a, b);
        loop invariant product_in_range(a, b);
        loop invariant abs_product % 2 == product % 2;
        loop assigns abs_product;
    */
    while (abs_product >= 2) {
        abs_product -= 2;
    }

    if (abs_product == 0) {
        is_even = 1;
    }

    //@ assert abs_product == product % 2;
    //@ assert product == a * b;
    
    return is_even;
}
