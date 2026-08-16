/*@
    predicate eq_plus_three(integer a, integer b) = a + 3 == b + 2;
    predicate eq_plus_two(integer b, integer c) = b + 2 == c + 1;
    predicate eq_plus_one(integer a, integer c) = a + 3 == c + 1;
*/

/*@
    lemma complex_calc_combining_example:
        \forall integer a, b, c;
            eq_plus_three(a, b) && eq_plus_two(b, c) ==> eq_plus_one(a, c);
*/

void main() {
    //@ assert \true;
}
