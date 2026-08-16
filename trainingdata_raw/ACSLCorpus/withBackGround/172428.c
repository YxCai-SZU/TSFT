/*@
    predicate a_equals_b(integer a, integer b) = a == b;
    predicate b_equals_c(integer b, integer c) = b == c;
    predicate a_equals_c(integer a, integer c) = a == c;
*/

/*@
    lemma calc_example_y: 
        \forall integer a, b, c; 
        a_equals_b(a, b) && b_equals_c(b, c) ==> a_equals_c(a, c);
*/

/*@
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate diff_nonneg(integer a, integer b) = b - a >= 0;
*/

/*@
    lemma proof_example: 
        \forall integer a, b; 
        a_le_b(a, b) ==> a_le_b(a, b);
*/

/*@
    lemma proof_example2: 
        \forall integer a, b; 
        a_le_b(a, b) ==> a_le_b(a, b);
*/

int main() {
    return 0;
}
