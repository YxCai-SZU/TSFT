/*@
    predicate is_nonzero(integer y) = y != 0;

    logic integer quotient(integer x, integer y) = x / y;
    logic integer remainder(integer x, integer y) = x % y;

    lemma division_lemma:
        \forall integer x, y;
        is_nonzero(y) ==> x == quotient(x, y) * y + remainder(x, y);
*/

/*@
    logic integer map_value(integer k) = k > 0 && k < 5 ? k * 3 : 0;
    predicate in_domain(integer k) = k > 0 && k < 5;
*/

/*@
    assigns \nothing;
    ensures \result == map_value(k);
*/
int map_value(int k) {
    return k > 0 && k < 5 ? k * 3 : 0;
}

/*@
    assigns \nothing;
*/
int main() {
    int q;
    int r;
    int x;
    int y;
    int m1_k;
    int m1_v;

    // Test quotient and remainder
    x = 10;
    y = 3;
    /*@ assert y != 0; */
    //@ assert x == quotient(x, y) * y + remainder(x, y);
    q = x / y;
    r = x % y;
    //@ assert 3 * q + r == 10;

    // Test map properties
    m1_k = 4;
    /*@ assert in_domain(m1_k); */
    m1_v = map_value(m1_k);
    //@ assert m1_v == 12;

    return 0;
}
