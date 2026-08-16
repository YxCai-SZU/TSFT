/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        0 <= (r) <= (n) + (m));
    ensures \result == ((n) + (m) - (r));
    assigns \nothing;
*/
int func(int n, int m, int r)
{
    int result;

    //@ assert ((n) + (m) - (r)) >= 0;
    //@ assert ((n) + (m) - (r)) <= 2147483647;

    result = n + m - r;
    return result;
}
