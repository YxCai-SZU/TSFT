/*@
    predicate int_gt(integer a, integer b) = a > b;
    predicate int_lt(integer a, integer b) = a < b;
    predicate int_ge(integer a, integer b) = a >= b;
    predicate int_le(integer a, integer b) = a <= b;
    predicate int_eq(integer a, integer b) = a == b;
    predicate bool_eq(boolean a, boolean b) = a == b;
    predicate bool_neq(boolean a, boolean b) = a != b;

    lemma calc_example_7:
        \forall integer a, b, c;
            int_gt(a, b) && int_gt(b, c) ==> int_gt(a, c);

    lemma assert_rel_int:
        \forall integer a, b, c;
            int_gt(a, b) && int_gt(b, c) ==> int_gt(a, c);

    lemma assert_rel_bool:
        \forall boolean a, b;
            (a == \true) && (b == \false) ==> bool_neq(a, b);

    lemma assert_rel_int_equal:
        \forall integer a, b, c;
            int_eq(a, b) && int_eq(b, c) ==> int_eq(a, c);

    lemma assert_rel_int_less:
        \forall integer a, b;
            int_lt(a, b) ==> int_le(a, b);

    lemma assert_rel_int_greater:
        \forall integer a, b;
            int_gt(a, b) ==> int_ge(a, b);

    lemma assert_rel_int_equal_or_greater:
        \forall integer a, b;
            int_ge(a, b) ==> int_ge(a, b);

    lemma assert_rel_int_equal_or_less:
        \forall integer a, b;
            int_le(a, b) ==> int_le(a, b);

    lemma assert_rel_int_range:
        \forall integer a, b, c;
            int_le(a, b) && int_le(b, c) ==> int_le(a, c);
*/

/*@
    requires a > b && b > c;
    ensures \result == 1;
*/
int calc_example_7(int a, int b, int c) {
    //@ assert a > b;
    //@ assert b > c;
    //@ assert a > c;
    return 1;
}

/*@
    requires a > b && b > c;
    ensures \result == 1;
*/
int assert_rel_int(int a, int b, int c) {
    //@ assert a > c;
    return 1;
}

/*@
    requires a == 1 && b == 0;
    ensures \result == 1;
*/
int assert_rel_bool(int a, int b) {
    //@ assert a != b;
    return 1;
}

/*@
    requires a == b && b == c;
    ensures \result == 1;
*/
int assert_rel_int_equal(int a, int b, int c) {
    //@ assert a == c;
    return 1;
}

/*@
    requires a < b;
    ensures \result == 1;
*/
int assert_rel_int_less(int a, int b) {
    //@ assert a <= b;
    return 1;
}

/*@
    requires a > b;
    ensures \result == 1;
*/
int assert_rel_int_greater(int a, int b) {
    //@ assert a >= b;
    return 1;
}

/*@
    requires a >= b;
    ensures \result == 1;
*/
int assert_rel_int_equal_or_greater(int a, int b) {
    //@ assert a >= b;
    return 1;
}

/*@
    requires a <= b;
    ensures \result == 1;
*/
int assert_rel_int_equal_or_less(int a, int b) {
    //@ assert a <= b;
    return 1;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
*/
int assert_rel_int_range(int a, int b, int c) {
    //@ assert a <= c;
    return 1;
}

int main() {
    return 0;
}
