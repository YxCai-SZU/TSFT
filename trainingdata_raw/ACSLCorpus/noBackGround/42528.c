/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result <= b;
    ensures \result <= c;
    ensures \result <= d;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_tot;
    int x;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    if (min_ab < min_cd) {
        min_tot = min_ab;
    } else {
        min_tot = min_cd;
    }

    x = min_tot;

    //@ assert x >= 0 && x <= a && x <= b && x <= c && x <= d;

    return x;
}
