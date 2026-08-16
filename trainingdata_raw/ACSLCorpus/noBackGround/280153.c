/*@
    requires 1 <= a <= 1000;
    requires 1 <= b <= 1000;
    requires 1 <= c <= 1000;
    requires 1 <= d <= 1000;
    ensures \result >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ab;
    int cd;
    int res;

    //@ assert (((a) < (b) ==> (((a) < (b) ? (a) : (b))) == (a)) && ((a) >= (b) ==> (((a) < (b) ? (a) : (b))) == (b)));
    //@ assert (((c) < (d) ==> (((c) < (d) ? (c) : (d))) == (c)) && ((c) >= (d) ==> (((c) < (d) ? (c) : (d))) == (d)));

    if (a < b) {
        ab = a;
    } else {
        ab = b;
    }

    if (c < d) {
        cd = c;
    } else {
        cd = d;
    }

    //@ assert ab >= ((a) < (b) ? (a) : (b));
    //@ assert cd >= ((c) < (d) ? (c) : (d));

    res = ab + cd;
    //@ assert res >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    return res;
}
