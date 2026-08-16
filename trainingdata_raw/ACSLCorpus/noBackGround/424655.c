/*@
    requires (-100 <= (a) && (a) <= 100 &&
        -100 <= (b) && (b) <= 100 &&
        -100 <= (c) && (c) <= 100);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    assigns \nothing;
*/
long func(long a, long b, long c)
{
    long ans;

    //@ assert (-100 <= (a) && (a) <= 100 &&         -100 <= (b) && (b) <= 100 &&         -100 <= (c) && (c) <= 100);

    if (a == b) {
        ans = c;
        //@ assert a == b && ans == c;
    } else if (b == c) {
        ans = a;
        //@ assert b == c && ans == a;
    } else {
        ans = b;
        //@ assert ans == b;
    }

    //@ assert ans == ((a) == (b) ? (c) : ((b) == (c) ? (a) : (b)));
    return ans;
}
