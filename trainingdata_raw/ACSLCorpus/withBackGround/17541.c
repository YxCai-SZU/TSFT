/*@
    predicate lt_chain(integer a, integer b, integer c) = a < b && b < c;

    lemma proof_example_3: \forall integer a, b, c; lt_chain(a, b, c) ==> a + (c - b) == c - (b - a);
    lemma calc_example_3: \forall integer a, b, c; lt_chain(a, b, c) ==> a + (c - b) == c - (b - a);
    lemma check_add_associative: \forall integer a, b, c; (a + b) + c == a + (b + c);
    lemma check_add_communicative: \forall integer a, b; a + b == b + a;
    lemma check_additiveInverse: \forall integer a; a + (-a) == 0;
    lemma check_additiveIdentity: \forall integer a; a + 0 == a;
*/

int main() {
    return 0;
}
