/*@
    predicate identity(integer n) = n == n;

    lemma identity_lemma:
        \forall integer n; identity(n);

    predicate transitive(integer a, integer b, integer c) =
        a <= b && b <= c ==> a <= c;

    lemma transitive_lemma:
        \forall integer a, b, c; transitive(a, b, c);

    predicate strict_transitive(integer a, integer b, integer c) =
        a < b && b < c ==> a < c;

    lemma strict_transitive_lemma:
        \forall integer a, b, c; strict_transitive(a, b, c);

    predicate nonlinear_arith(integer a, integer b, integer c) =
        a * b <= c ==> a * b <= c;

    lemma nonlinear_arith_lemma:
        \forall integer a, b, c; nonlinear_arith(a, b, c);
*/

/*@
    requires n == 10;
    ensures \result == 20;
*/
int calc_example_5(int n) {
    //@ assert n == 10;
    int result;
    result = n * 2;
    //@ assert result == 20;
    return result;
}

/*@
    requires a == 2 && b == 5 && c == 10;
    ensures \result == 1;
*/
int calc_example_6(int a, int b, int c) {
    //@ assert a == 2 && b == 5 && c == 10;
    int result;
    result = a * 2;
    //@ assert result <= c;
    return 1;
}

/*@
    requires a == 2 && b == 5 && c == 10;
    ensures \result == 1;
*/
int calc_example_7(int a, int b, int c) {
    //@ assert a == 2 && b == 5 && c == 10;
    int result;
    result = a * 2;
    //@ assert result < c;
    return 1;
}

/*@
    requires a == 2 && b == 5 && c == 10;
    ensures \result == 1;
*/
int calc_example_8(int a, int b, int c) {
    //@ assert a == 2 && b == 5 && c == 10;
    int result;
    result = a * b;
    //@ assert result <= c;
    return 1;
}

int main() {
    int n;
    int a;
    int b;
    int c;
    
    n = 10;
    calc_example_5(n);
    
    a = 2;
    b = 5;
    c = 10;
    calc_example_6(a, b, c);
    calc_example_7(a, b, c);
    calc_example_8(a, b, c);
    
    return 0;
}
