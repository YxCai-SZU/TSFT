/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int res;
    unsigned int i;

    i = 0;
    /*@
        loop invariant 0 <= i <= 10000000;
        loop assigns i;
        loop variant 10000000 - i;
    */
    while (i < 10000000) {
        i = i + 1;
    }

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 10000;

    res = a * b;
    return res;
}

int main(void) {
    return 0;
}
