/*@
predicate le_integer(integer a, integer b) = a <= b;
predicate eq_integer(integer a, integer b) = a == b;
*/

/*@
lemma calc_context_example_1:
    \forall integer a, b; a <= b ==> a <= b;
lemma calc_context_example_2:
    \forall integer x, y; x <= y ==> x <= y;
lemma calc_context_example_3:
    \forall integer x, y; x == y ==> x == y;
*/

/*@
requires a <= b && b == c;
ensures a <= c;
*/
void example_of_proofs(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b == c;
}

int main() {
    return 0;
}
