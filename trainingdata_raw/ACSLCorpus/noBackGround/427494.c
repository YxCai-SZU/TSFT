/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= b + c + 1 + a;
*/
long func(long a, long b, long c) {
    long min_val;
    long result;

    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);

    if (c < a + b + 1) {
        min_val = c;
        //@ assert min_val == c;
    } else {
        min_val = a + b + 1;
        //@ assert min_val == a + b + 1;
    }

    //@ assert min_val == ((c) < (a) + (b) + 1 ? (c) : (a) + (b) + 1);
    //@ assert min_val >= 0;
    result = b + min_val;
    //@ assert result >= 0;
    //@ assert result <= b + c + 1 + a;
    return result;
}
