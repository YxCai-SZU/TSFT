/*@
    requires (0 <= (a) <= 123 &&
        0 <= (b) <= 123 &&
        0 <= (c) <= 123 &&
        0 <= (d) <= 123 &&
        0 <= (e) <= 123 &&
        0 <= (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    //@ ghost int original_a = a;
    //@ ghost int original_e = e;

    dist = e - a;

    //@ assert dist == original_e - original_a;
    //@ assert dist >= 0;
    //@ assert dist <= 123;

    return dist <= k;
}
