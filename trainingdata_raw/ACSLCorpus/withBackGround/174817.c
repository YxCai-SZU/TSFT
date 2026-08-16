/*@
    predicate commutative_add(integer a, integer b) = a + b == b + a;
    predicate commutative_mul(integer a, integer b) = a * b == b * a;
    predicate triple_add_comm(integer a, integer b, integer c) = a + b + c == c + b + a;
    predicate triple_mul_comm(integer a, integer b, integer c) = a * b * c == b * c * a;
*/

/*@ lemma calc_example_11: \forall integer a, b; commutative_add(a, b) ==> commutative_add(a, b); */
/*@ lemma calc_example_12: \forall integer a, b; commutative_mul(a, b) ==> commutative_mul(a, b); */
/*@ lemma calc_example_13: \forall integer a, b, c; triple_add_comm(a, b, c) ==> triple_add_comm(a, b, c); */
/*@ lemma calc_example_14: \forall integer a, b; commutative_add(a, b) && commutative_mul(a, b) ==> commutative_add(a, b) && commutative_mul(a, b); */
/*@ lemma calc_example_15: \forall integer a, b, c; triple_add_comm(a, b, c) && triple_mul_comm(a, b, c) ==> triple_add_comm(a, b, c) && triple_mul_comm(a, b, c); */

int main() {
    return 0;
}
