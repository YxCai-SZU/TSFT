/*@
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate b_le_c(integer b, integer c) = b <= c;
    predicate a_le_c(integer a, integer c) = a <= c;

    lemma calc_example_dd: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);
    lemma three_numbers: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);
    lemma three_numbers2: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);
    lemma three_numbers3: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);
    lemma three_numbers4: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);
*/

/*@
    logic integer product(integer a, integer b, integer c) = a * b * c;
    predicate bounds(integer a, integer b, integer c) = 
        0 <= a && a <= 10 && 0 <= b && b <= 10 && 0 <= c && c <= 10;
    predicate product_bound(integer a, integer b, integer c) = product(a, b, c) <= 1000;

    lemma product_constant: \forall integer a, b, c; bounds(a, b, c) ==> product_bound(a, b, c);
*/

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_dd_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
    requires 0 <= a && a <= 10 && 0 <= b && b <= 10 && 0 <= c && c <= 10;
    ensures \result == 0;
    assigns \nothing;
*/
int product_constant_impl(int a, int b, int c) {
    //@ assert 0 <= a && a <= 10;
    //@ assert 0 <= b && b <= 10;
    //@ assert 0 <= c && c <= 10;
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int three_numbers_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int three_numbers2_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int three_numbers3_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int three_numbers4_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

int main() {
    return 0;
}
