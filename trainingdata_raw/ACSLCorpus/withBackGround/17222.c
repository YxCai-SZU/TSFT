/*@
    predicate is_within_range(integer x) = 1 <= x && x <= 100;

    lemma calc_example_7:
        \forall integer x, y;
            is_within_range(x) && is_within_range(y) ==> x + y <= 200;

    lemma calc_example_8:
        \forall integer a;
            a == a + 1 - 1;

    lemma calc_example_9:
        \forall integer a;
            a <= a + 2;

    lemma calc_example_10:
        \forall integer a;
            a <= a + 3;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == x + y;
    ensures \result <= 200;
*/
int add_within_range(int x, int y) {
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert x + y <= 100 + 100;
    //@ assert x + y <= 200;
    int result;
    result = x + y;
    return result;
}

/*@
    requires \true;
    ensures \result == a + 1 - 1;
*/
int identity_plus_one_minus_one(int a) {
    int result;
    result = a + 1 - 1;
    //@ assert result == a;
    return result;
}

/*@
    requires \true;
    ensures \result == a + 2;
    ensures a <= \result;
*/
int add_two(int a) {
    int result;
    result = a + 2;
    //@ assert a <= result;
    return result;
}

/*@
    requires \true;
    ensures \result == a + 3;
    ensures a <= \result;
*/
int add_three(int a) {
    int result;
    result = a + 3;
    //@ assert a <= result;
    return result;
}

int main() {
    return 0;
}
