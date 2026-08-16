/*@
    predicate positive(integer a) = a > 0;

    lemma non_linear_arith_example1:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
            a * b <= a * (b + c);

    lemma non_linear_arith_example2:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
            a * b <= b * (a + c);

    lemma non_linear_arith_example3:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
            a * b <= (a + c) * (b + c) - c * c;

    lemma non_linear_arith_example4:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
            a * b <= (a + c) * (b + c) - c * (b + c);
*/

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_example1(int a, int b, int c) {
    //@ assert a * b <= a * (b + c);
    return 0;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_example2(int a, int b, int c) {
    //@ assert a * b <= b * (a + c);
    return 0;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_example3(int a, int b, int c) {
    //@ assert a * b <= (a + c) * (b + c) - c * c;
    return 0;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_example4(int a, int b, int c) {
    //@ assert a * b <= (a + c) * (b + c) - c * (b + c);
    return 0;
}

int main() {
    return 0;
}
