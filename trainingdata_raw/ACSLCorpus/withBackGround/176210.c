/*@
predicate is_even(integer x) = x % 2 == 0;

lemma calc_example_9: \forall integer m; is_even(m) ==> is_even(m + 4);
lemma calc_example_10: \forall integer a, b, c; a < b && b < c ==> a < c;
lemma calc_example_11: \forall integer x, y; x == y && y < 5 ==> x < 5;
*/

/*@
requires is_even(m);
ensures is_even(m + 4);
*/
void calc_example_9(int m) {
    //@ assert is_even(m);
    //@ assert is_even(m + 4);
}

/*@
requires a < b && b < c;
ensures a < c;
*/
void calc_example_10(int a, int b, int c) {
    //@ assert a < b;
    //@ assert b < c;
    //@ assert a < c;
}

/*@
requires x == y && y < 5;
ensures x < 5;
*/
void calc_example_11(int x, int y) {
    //@ assert x == y;
    //@ assert y < 5;
    //@ assert x < 5;
}

int main() {
    return 0;
}
