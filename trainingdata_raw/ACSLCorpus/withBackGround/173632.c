/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate no_overflow(integer l) = l <= 2147483647 / 4;
*/

/*@
    logic integer perimeter_square_logic(integer l) = 4 * l;
*/

/*@
    lemma perimeter_bound: 
        \forall integer l; is_nonnegative(l) && no_overflow(l) ==> 
        perimeter_square_logic(l) <= 2147483647;
*/

/*@
    requires is_nonnegative(l) && no_overflow(l);
    ensures \result == perimeter_square_logic(l);
    assigns \nothing;
*/
int perimeter_square(int l) {
    //@ assert is_nonnegative(l);
    //@ assert no_overflow(l);
    //@ assert perimeter_square_logic(l) <= 2147483647;
    return 4 * l;
}

int main() {
    return 0;
}
