/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures ((\result) == (((a)) + ((b)) + 10 * ((c))) ||
        (\result) == (((a)) + ((c)) + 10 * ((b))) ||
        (\result) == (((b)) + ((c)) + 10 * ((a))));
*/
long func(long a, long b, long c) {
    long ans1;
    long ans2;
    long ans3;
    long max_val;

    ans1 = a + b + 10 * c;
    ans2 = a + c + 10 * b;
    ans3 = b + c + 10 * a;

    max_val = ans1;
    //@ assert max_val == ans1 || max_val == ans2 || max_val == ans3;

    if (ans2 > max_val) {
        max_val = ans2;
        //@ assert max_val == ans1 || max_val == ans2 || max_val == ans3;
    }

    if (ans3 > max_val) {
        max_val = ans3;
        //@ assert max_val == ans1 || max_val == ans2 || max_val == ans3;
    }

    //@ assert max_val == ans1 || max_val == ans2 || max_val == ans3;
    return max_val;
}
