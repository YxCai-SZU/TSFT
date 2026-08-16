/*@
    predicate is_nonnegative(integer v) = v >= 0;

    lemma calc_example_7:
        \forall integer x, y;
            y == x * 2 ==> y >= x + x;

    lemma prove_greater_than_or_equal:
        \forall integer a, b, c;
            a == b * 2 && b == c * 2 && is_nonnegative(c) ==> a >= c + c + c;
*/

/*@
    requires y == x * 2;
    ensures \result >= x + x;
*/
int calc_example_7(int x, int y) {
    //@ assert y == x * 2;
    //@ assert x * 2 >= x + x;
    return y;
}

/*@
    requires a == b * 2;
    requires b == c * 2;
    requires c >= 0;
    ensures \result >= c + c + c;
*/
int prove_greater_than_or_equal(int a, int b, int c) {
    //@ assert a == b * 2;
    //@ assert b * 2 >= c * 2 * 2;
    //@ assert c * 2 * 2 >= c + c + c;
    return a;
}

int main() {
    return 0;
}
