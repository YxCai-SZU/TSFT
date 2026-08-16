/*@
predicate non_negative(integer a) = a >= 0;
predicate bounded(integer a) = a <= 10;
predicate cubic_bound(integer a) = a * a * a <= 1000;
predicate square_bound(integer a) = a * a <= 100;
predicate chain_inequality(integer a) = a + 1 <= a + 2 && a + 2 <= a + 3 && a + 3 <= a + 4;

lemma calc_chain: \forall integer a; chain_inequality(a);
lemma cubic_proof: \forall integer a; non_negative(a) && bounded(a) ==> cubic_bound(a);
lemma square_proof: \forall integer a; non_negative(a) && bounded(a) ==> square_bound(a);
*/

/*@
requires non_negative(a) && bounded(a);
ensures cubic_bound(a);
*/
void non_linear_arith(int a) {
    //@ assert a * a * a <= 10 * 10 * 10;
}

/*@
requires non_negative(a) && bounded(a);
ensures square_bound(a);
*/
void sqrt_arith(int a) {
    //@ assert a * a <= 10 * 10;
}

/*@
ensures chain_inequality(a);
*/
void calc_example_2(int a) {
    //@ assert a + 1 <= a + 2;
    //@ assert a + 2 <= a + 3;
    //@ assert a + 3 <= a + 4;
}

int main() {
    return 0;
}
