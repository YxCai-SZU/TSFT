/*@
predicate greater_than(integer a, integer b) = a > b;
predicate greater_eq(integer a, integer b) = a >= b;
predicate positive(integer x) = x > 0;

lemma transitive_greater:
  \forall integer a, b, c;
    greater_than(a, b) && greater_than(b, c) ==> greater_than(a, c);

lemma non_strict_transitive_greater:
  \forall integer a, b, c;
    greater_eq(a, b) && greater_eq(b, c) ==> greater_eq(a, c);

lemma example_nonlinear:
  \forall integer a, b, c;
    greater_eq(a, b) && greater_eq(b, c) && positive(c) ==> greater_eq(a, c);
*/

/*@
  requires a > b && b > c;
  ensures \result > 0;
*/
int transitive_greater_than(int a, int b, int c) {
    //@ assert a > b && b > c;
    //@ assert a > c;
    return a - c;
}

/*@
  requires a >= b && b >= c;
  ensures \result >= 0;
*/
int non_strict_transitive_greater_than(int a, int b, int c) {
    //@ assert a >= b && b >= c;
    //@ assert a >= c;
    return a - c;
}

/*@
  requires a >= b && b >= c && c > 0;
  ensures \result >= 0;
*/
int example_nonlinear_arith(int a, int b, int c) {
    //@ assert a >= b && b >= c;
    //@ assert a >= c;
    return a - c;
}

int main() {
    return 0;
}
