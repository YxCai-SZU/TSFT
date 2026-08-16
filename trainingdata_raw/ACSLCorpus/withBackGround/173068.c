/*@
    lemma calc_example_15: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_2: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_3: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_4: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_5: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_6: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_7: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_8: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_9: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
    lemma example_15_test_10: \forall integer a, b, c; a <= b && b <= c ==> a <= c + 1;
*/

/*@
    requires a <= b;
    requires b <= c;
    ensures \result == 0;
    ensures a <= c + 1;
*/
int main_verification(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c + 1;
    return 0;
}
