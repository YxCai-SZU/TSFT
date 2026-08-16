/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    ensures \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d)) || \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d)) + 1;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long min1;
    long min2;
    long ans;
    int is_less;

    //@ assert (((a) < (b) ==> (((a) < (b) ? (a) : (b))) == (a)) && ((a) >= (b) ==> (((a) < (b) ? (a) : (b))) == (b)));
    //@ assert (((c) < (d) ==> (((c) < (d) ? (c) : (d))) == (c)) && ((c) >= (d) ==> (((c) < (d) ? (c) : (d))) == (d)));

    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }
    //@ assert (((a) < (b) ==> (min1) == (a)) && ((a) >= (b) ==> (min1) == (b)));

    if (c < d) {
        min2 = c;
    } else {
        min2 = d;
    }
    //@ assert (((c) < (d) ==> (min2) == (c)) && ((c) >= (d) ==> (min2) == (d)));

    ans = min1 + min2;
    //@ assert ans == min1 + min2;

    if (min1 < min2) {
        is_less = 1;
    } else {
        is_less = 0;
    }

    if (is_less) {
        ans = ans + 1;
        //@ assert ans == min1 + min2 + 1;
    } else {
        //@ assert ans == min1 + min2;
    }

    //@ assert ans >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    //@ assert ans == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d)) || ans == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d)) + 1;

    return ans;
}
