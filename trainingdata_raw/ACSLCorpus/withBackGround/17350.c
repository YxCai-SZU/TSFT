/*@
    predicate a_less_b_plus_one(integer a, integer b) = a < b + 1;

    lemma calc_example_1:
        \forall integer a, b; a < b ==> a_less_b_plus_one(a, b);
*/

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate square_in_range(integer a) = a * a <= 100 * 100;

    lemma func_1:
        \forall integer a; a_in_range(a) ==> square_in_range(a);
*/

void main() {
    //@ assert \true;
}
