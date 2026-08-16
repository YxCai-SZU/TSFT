/*@
    predicate le(integer a, integer b) = a <= b;

    lemma transitivity:
        \forall integer x, y, z;
            le(x, y) && le(y, z) ==> le(x, z);
*/

/*@
    requires x <= y;
    requires y <= z;
    ensures \result == 0;
*/
int calc_example_3(int x, int y, int z) {
    //@ assert x <= y;
    //@ assert y <= z;
    //@ assert x <= z;
    return 0;
}

/*@
    ensures \result == 0;
*/
int test_example_3(void) {
    int x;
    int y;
    int z;
    int tmp;

    x = 2;
    y = 5;
    z = 7;
    //@ assert x <= y;
    //@ assert y <= z;
    //@ assert x <= z;
    tmp = calc_example_3(x, y, z);
    return 0;
}

/*@
    ensures \result == 0;
*/
int test_example_4(void) {
    int x;
    int y;
    int z;
    int tmp;

    x = 3;
    y = 5;
    z = 7;
    //@ assert x <= y;
    //@ assert y <= z;
    //@ assert x <= z;
    tmp = calc_example_3(x, y, z);
    return 0;
}

int main(void) {
    return 0;
}
