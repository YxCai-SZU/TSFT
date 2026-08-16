/*@
predicate lt_chain(integer a) =
    a < a + 1 < a + 2 < a + 3 < a + 4 < a + 5 < a + 6 < a + 7 < a + 8 < a + 9 < a + 10;

lemma calc_example_5:
    \forall integer x, y; x > y ==> x - y > 0;

lemma example_for_calc_steps:
    \forall integer a; a < 100 ==> lt_chain(a);
*/

void main() {
    //@ assert \true;
}
