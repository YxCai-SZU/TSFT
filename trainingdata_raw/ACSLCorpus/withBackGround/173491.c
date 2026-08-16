/*@
    predicate addition_commutative(integer x, integer y) = x + y == y + x;
    predicate addition_three_commutative(integer x, integer y, integer z) = x + y + z == z + y + x;
    predicate multiplication_commutative(integer x, integer y) = x * y == y * x;
    predicate distributive_right(integer x, integer y, integer z) = (x + y) * z == x * z + y * z;
    predicate distributive_left(integer x, integer y, integer z) = x * (y + z) == x * y + x * z;
    predicate multiplication_associative(integer x, integer y, integer z) = (x * y) * z == x * (y * z);
*/

/*@
    lemma addition_commutative_lemma: \forall integer x, y; addition_commutative(x, y);
    lemma addition_three_commutative_lemma: \forall integer x, y, z; addition_three_commutative(x, y, z);
    lemma multiplication_commutative_lemma: \forall integer x, y; multiplication_commutative(x, y);
    lemma distributive_right_lemma: \forall integer x, y, z; distributive_right(x, y, z);
    lemma distributive_left_lemma: \forall integer x, y, z; distributive_left(x, y, z);
    lemma multiplication_associative_lemma: \forall integer x, y, z; multiplication_associative(x, y, z);
*/

/*@
    requires x >= 0 && y >= 0;
    ensures 2 * x + 3 * y == 3 * y + 2 * x;
*/
void calc_example_5(int x, int y) {
    //@ assert addition_commutative(2 * x, 3 * y);
}

/*@
    requires x >= 0 && y >= 0;
    ensures 5 * (x + y) == 5 * x + 5 * y;
*/
void calc_example_6(int x, int y) {
    //@ assert distributive_right(5, x, y);
}

int main() {
    return 0;
}
