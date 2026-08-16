/*@
    predicate is_greater_than(integer a, integer b) = a > b;
    predicate is_greater_or_equal(integer a, integer b) = a >= b;
    predicate is_less_than(integer a, integer b) = a < b;
    predicate is_less_or_equal(integer a, integer b) = a <= b;
    predicate is_equal(integer a, integer b) = a == b;
    predicate is_not_equal(integer a, integer b) = a != b;

    lemma calc_example_4:
        \forall integer a, b, c;
            is_greater_than(a, b) && is_greater_or_equal(b, c) ==>
            is_greater_or_equal(a, c);

    lemma assert_bounds:
        \forall integer a, b, c;
            is_greater_than(a, b) && is_greater_or_equal(b, c) &&
            is_greater_or_equal(a, c) ==> \true;

    lemma assert_chain_bounds:
        \forall integer a, b, c;
            is_greater_than(a, b) && is_greater_or_equal(b, c) &&
            is_greater_or_equal(a, c) ==> \true;

    lemma assert_equality:
        \forall integer a, b;
            is_equal(a, b) ==> \true;

    lemma assert_equality_chain:
        \forall integer a, b;
            is_equal(a, b) ==> \true;

    lemma assert_inequality:
        \forall integer a, b;
            is_not_equal(a, b) ==> \true;

    lemma assert_inequality_chain:
        \forall integer a, b;
            is_not_equal(a, b) ==> \true;

    lemma assert_greater_than_or_equal:
        \forall integer a, b;
            is_greater_or_equal(a, b) ==> \true;

    lemma assert_greater_than_or_equal_chain:
        \forall integer a, b;
            is_greater_or_equal(a, b) ==> \true;

    lemma assert_greater_than:
        \forall integer a, b;
            is_greater_than(a, b) ==> \true;

    lemma assert_greater_than_chain:
        \forall integer a, b;
            is_greater_than(a, b) ==> \true;

    lemma assert_less_than_or_equal:
        \forall integer a, b;
            is_less_or_equal(a, b) ==> \true;

    lemma assert_less_than_or_equal_chain:
        \forall integer a, b;
            is_less_or_equal(a, b) ==> \true;

    lemma assert_less_than:
        \forall integer a, b;
            is_less_than(a, b) ==> \true;

    lemma assert_less_than_chain:
        \forall integer a, b;
            is_less_than(a, b) ==> \true;
*/

#include <stdbool.h>

/*@
    requires a > b;
    requires b >= c;
    ensures \result == true;
*/
bool calc_example_4_c(unsigned char a, unsigned char b, unsigned char c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
    return true;
}

/*@
    requires a > b;
    requires b >= c;
    requires a >= c;
    ensures \result == true;
*/
bool assert_bounds_c(unsigned char a, unsigned char b, unsigned char c) {
    //@ assert a >= c;
    return true;
}

/*@
    requires a > b;
    requires b >= c;
    requires a >= c;
    ensures \result == true;
*/
bool assert_chain_bounds_c(unsigned char a, unsigned char b, unsigned char c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
    return true;
}

/*@
    requires a == b;
    ensures \result == true;
*/
bool assert_equality_c(unsigned char a, unsigned char b) {
    //@ assert a == b;
    return true;
}

/*@
    requires a == b;
    ensures \result == true;
*/
bool assert_equality_chain_c(unsigned char a, unsigned char b) {
    //@ assert a == b;
    return true;
}

/*@
    requires a != b;
    ensures \result == true;
*/
bool assert_inequality_c(unsigned char a, unsigned char b) {
    //@ assert a != b;
    return true;
}

/*@
    requires a != b;
    ensures \result == true;
*/
bool assert_inequality_chain_c(unsigned char a, unsigned char b) {
    //@ assert a != b;
    return true;
}

/*@
    requires a >= b;
    ensures \result == true;
*/
bool assert_greater_than_or_equal_c(unsigned char a, unsigned char b) {
    //@ assert a >= b;
    return true;
}

/*@
    requires a >= b;
    ensures \result == true;
*/
bool assert_greater_than_or_equal_chain_c(unsigned char a, unsigned char b) {
    //@ assert a >= b;
    return true;
}

/*@
    requires a > b;
    ensures \result == true;
*/
bool assert_greater_than_c(unsigned char a, unsigned char b) {
    //@ assert a > b;
    return true;
}

/*@
    requires a > b;
    ensures \result == true;
*/
bool assert_greater_than_chain_c(unsigned char a, unsigned char b) {
    //@ assert a > b;
    return true;
}

/*@
    requires a <= b;
    ensures \result == true;
*/
bool assert_less_than_or_equal_c(unsigned char a, unsigned char b) {
    //@ assert a <= b;
    return true;
}

/*@
    requires a <= b;
    ensures \result == true;
*/
bool assert_less_than_or_equal_chain_c(unsigned char a, unsigned char b) {
    //@ assert a <= b;
    return true;
}

/*@
    requires a < b;
    ensures \result == true;
*/
bool assert_less_than_c(unsigned char a, unsigned char b) {
    //@ assert a < b;
    return true;
}

/*@
    requires a < b;
    ensures \result == true;
*/
bool assert_less_than_chain_c(unsigned char a, unsigned char b) {
    //@ assert a < b;
    return true;
}

int main() {
    return 0;
}
