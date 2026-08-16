/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == (x + 1) / 2;
*/
int func(int x) {
    int result = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= x;
        loop invariant result == (i + 1) / 2;
        loop assigns i, result;
        loop variant x - i;
    */
    while (i < x) {
        if (i % 2 == 0) {
            //@ assert result == (i + 1) / 2;
            result += 1;
            //@ assert result == (i + 1) / 2 + 1;
        }
        i += 1;
        //@ assert result == (i + 1) / 2;
    }
    return result;
}
