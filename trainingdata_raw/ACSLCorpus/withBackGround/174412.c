/*@
    predicate positive(integer x) = x > 0;
    predicate nonnegative(integer x) = x >= 0;

    lemma nonlinear_arithmetic_example_1: \forall integer x, y; positive(x) && positive(y) ==> nonnegative(x * y);
    lemma nonlinear_arithmetic_example_2: \forall integer a, b, c; positive(a) && positive(b) && positive(c) ==> nonnegative(a * b * c);
    lemma nonlinear_arithmetic_example_3: \forall integer a, b, c; positive(a) && positive(b) && positive(c) ==> nonnegative(a * (b * c));
    lemma nonlinear_arithmetic_example_4: \forall integer a, b, c; positive(a) && positive(b) && positive(c) ==> nonnegative(a * (b + c));
    lemma nonlinear_arithmetic_example_5: \forall integer a, b, c; positive(a) && positive(b) && positive(c) ==> nonnegative(a * (b * c) + a);
*/

/*@
    requires x > 0 && y > 0;
    ensures \result >= 0;
*/
int nonlinear_example_1(int x, int y) {
    //@ assert x > 0 && y > 0;
    int result = x * y;
    //@ assert result >= 0;
    return result;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result >= 0;
*/
int nonlinear_example_2(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    int intermediate = a * b;
    //@ assert intermediate >= 0;
    int result = intermediate * c;
    //@ assert result >= 0;
    return result;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result >= 0;
*/
int nonlinear_example_3(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    int intermediate = b * c;
    //@ assert intermediate >= 0;
    int result = a * intermediate;
    //@ assert result >= 0;
    return result;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result >= 0;
*/
int nonlinear_example_4(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    int sum = b + c;
    //@ assert sum > 0;
    int result = a * sum;
    //@ assert result >= 0;
    return result;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result >= 0;
*/
int nonlinear_example_5(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    int intermediate1 = b * c;
    //@ assert intermediate1 >= 0;
    int intermediate2 = a * intermediate1;
    //@ assert intermediate2 >= 0;
    int result = intermediate2 + a;
    //@ assert result >= 0;
    return result;
}

int main() {
    return 0;
}
