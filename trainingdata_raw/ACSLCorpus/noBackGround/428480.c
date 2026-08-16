/*@
    requires (1 <= (n) <= 1000000);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
unsigned int func(unsigned int n) {
    unsigned int count = 0;
    unsigned int i = 1;

    /*@
        loop invariant (1 <= (n) <= 1000000 &&
        1 <= (i) <= (n) + 1 &&
        0 <= (count) <= (i) - 1);
        loop assigns i, count;
        loop variant n + 1 - i;
    */
    while (i <= n) {
        //@ assert 0 <= count <= i - 1;
        if (n % i == 0) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count <= n;
    return count;
}
