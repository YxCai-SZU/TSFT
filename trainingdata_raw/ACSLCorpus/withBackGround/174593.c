/*@
    predicate f(integer i) = \true;

    lemma lemma_even_f:
        \forall integer i; 0 <= i < 10 && i % 2 == 0 ==> f(i);
*/

/*@
    requires 0 <= i < 10;
    requires i % 2 == 0;
    ensures \result == 1;
    assigns \nothing;
*/
int check_even_f(int i) {
    //@ assert f(i);
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    int i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> f(j);
        loop assigns i;
    */
    while (i < 10) {
        if (i % 2 == 0) {
            check_even_f(i);
        }
        i = i + 1;
    }
    return 0;
}
