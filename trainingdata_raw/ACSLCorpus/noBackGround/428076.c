/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    requires 1 <= d <= 5000;
    ensures \result >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int train;
    int bus;
    int ans;

    //@ assert 1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 5000 && 1 <= d <= 5000;

    if (a < b) {
        train = a;
        //@ assert (((a) < (b) ==> (train) == (a)) && ((a) >= (b) ==> (train) == (b)));
    } else {
        train = b;
        //@ assert (((a) < (b) ==> (train) == (a)) && ((a) >= (b) ==> (train) == (b)));
    }

    //@ assert train == ((a) < (b) ? (a) : (b));

    if (c < d) {
        bus = c;
        //@ assert (((c) < (d) ==> (bus) == (c)) && ((c) >= (d) ==> (bus) == (d)));
    } else {
        bus = d;
        //@ assert (((c) < (d) ==> (bus) == (c)) && ((c) >= (d) ==> (bus) == (d)));
    }

    //@ assert bus == ((c) < (d) ? (c) : (d));

    ans = train + bus;

    //@ assert ans >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));

    return ans;
}
