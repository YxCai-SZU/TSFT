/*@
    logic integer neg(integer x) = -x;

    lemma neg_lemma:
        \forall integer x; neg(x) == -x && neg(neg(x)) == x && neg(x) * 0 == 0;
*/

void test(void) {
    //@ assert neg(-10) == 10;
    //@ assert neg(neg(-10)) == -10;
    //@ assert neg(-10) * 0 == 0;
}

void further_tests(void) {
    //@ assert neg(100) == -100;
    //@ assert neg(-100) == 100;
}

int main(void) {
    return 0;
}
