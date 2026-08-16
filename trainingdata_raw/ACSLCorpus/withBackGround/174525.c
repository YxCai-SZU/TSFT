/*@
    predicate non_negative(integer v) = v >= 0;
    predicate within_range(integer v) = v >= 0 && v <= 100;
    predicate equality(integer a, integer b) = a == b;
    predicate sum_relation(integer a, integer b) = a == b + 2;
*/

/*@
    logic integer add_two(integer b) = b + 2;
*/

/*@
    lemma calc_example_7: \forall integer a, b; a - 2 == b ==> a == b + 2;
    lemma func_lemma: \forall integer x, y; 
        within_range(x) && within_range(y) && equality(x, y) ==> x <= y + 2;
*/

/*@
    requires a - 2 == b;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_7(int a, int b) {
    //@ assert a - 2 == b;
    //@ assert a == b + 2;
    return 1;
}

/*@
    requires non_negative(x) && non_negative(y);
    requires within_range(x) && within_range(y);
    requires equality(x, y);
    ensures \result == 1;
    assigns \nothing;
*/
int func(int x, int y) {
    //@ assert x == y;
    //@ assert y <= y + 2;
    //@ assert x <= y + 2;
    return 1;
}

int main() {
    return 0;
}
