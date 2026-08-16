/*@
    predicate is_positive(integer a) = a > 0;
    predicate is_negative(integer a) = a < 0;
    
    lemma calc_example_3:
        \forall integer x; x + 1 == x + 2 - 1 ==> x + 1 == x + 3 - 2;
    
    lemma example_equality_congruence:
        \forall integer a, b, c; a == b && b == c ==> a == c;
    
    lemma example_greater_than_equality:
        \forall integer a, b; a > 0 && a == b ==> b > 0;
    
    lemma example_less_than_equality:
        \forall integer a, b; a < 0 && a == b ==> b < 0;
*/

/*@
    requires x + 1 == x + 2 - 1;
    ensures \result == (x + 1 == x + 3 - 2);
    assigns \nothing;
*/
int calc_example_3(int x) {
    //@ assert x + 1 == x + 2 - 1;
    //@ assert x + 2 - 1 == x + 3 - 2;
    //@ assert x + 1 == x + 3 - 2;
    return (x + 1 == x + 3 - 2);
}

/*@
    requires a == b;
    requires b == c;
    ensures \result == (a == c);
    assigns \nothing;
*/
int example_equality_congruence(int a, int b, int c) {
    //@ assert a == c;
    return (a == c);
}

/*@
    requires a > 0;
    requires a == b;
    ensures \result == (b > 0);
    assigns \nothing;
*/
int example_greater_than_equality(int a, int b) {
    //@ assert b > 0;
    return (b > 0);
}

/*@
    requires a < 0;
    requires a == b;
    ensures \result == (b < 0);
    assigns \nothing;
*/
int example_less_than_equality(int a, int b) {
    //@ assert b < 0;
    return (b < 0);
}

int main() {
    return 0;
}
