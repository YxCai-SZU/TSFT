/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    int ab = a * b;
    int cd = c * d;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ab <= 100000000;
    //@ assert ab >= 1;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert cd <= 100000000;
    //@ assert cd >= 1;

    if (ab > cd) {
        result = ab;
    } else {
        result = cd;
    }

    return result;
}
