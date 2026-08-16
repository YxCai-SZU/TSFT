/*@
    predicate positive(integer a) = a > 0;
    predicate non_negative(integer a) = a >= 0;
    predicate leq(integer a, integer b) = a <= b;
*/

/*@
    lemma nonlinear_arithmetic_example_3:
        \forall integer a, b, c, d;
            positive(a) && positive(b) && positive(c) && positive(d) ==>
                a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_4:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
                a * b * c == (a * b) * c;
*/

/*@
    lemma nonlinear_arithmetic_example_5:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
                a * (b + c) == a * b + a * c;
*/

/*@
    requires positive(a) && positive(b) && positive(c) && positive(d);
    ensures \result == 0;
    assigns \nothing;
*/
int verify_nonlinear_arithmetic(int a, int b, int c, int d) {
    //@ assert a * b * c * d == (a * b) * (c * d);
    //@ assert a * b * c == (a * b) * c;
    //@ assert a * (b + c) == a * b + a * c;
    return 0;
}

/*@
    assigns \nothing;
*/
int main() {
    return verify_nonlinear_arithmetic(1, 2, 3, 4);
}
