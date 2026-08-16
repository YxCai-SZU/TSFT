/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (c) <= 20) && (1 <= (d) <= 20);
    ensures \result == ((c) * (d)) || \result == ((a) * (b));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int s1;
    int s2;
    int res;

    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    //@ assert (1 <= (c) <= 20) && (1 <= (d) <= 20);
    //@ assert 1 <= ((a) * (b)) <= 400;
    //@ assert 1 <= ((c) * (d)) <= 400;

    s1 = a * b;
    s2 = c * d;

    if (s1 > s2) {
        res = s1;
    } else {
        res = s2;
    }

    //@ assert res == ((c) * (d)) || res == ((a) * (b));
    //@ assert res >= 1;

    return res;
}
