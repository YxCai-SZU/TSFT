/*@
    requires (1 <= (N) && (N) <= 10000 &&
        0 <= (A) && (A) <= 1000);
    ensures \result == (((N) % 500) <= A);
*/
_Bool func(unsigned int N, unsigned int A)
{
    _Bool ans;
    unsigned int r;

    ans = 0;
    r = N % 500;

    //@ assert r == ((N) % 500);

    if (r <= A)
    {
        ans = 1;
    }

    //@ assert ans == (((N) % 500) <= A);
    return ans;
}
