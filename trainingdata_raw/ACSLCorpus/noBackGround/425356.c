/*@
    requires ((a) >= 0) && ((b) >= 0) && ((c) >= 0);
    requires ((k) >= 0) && k >= 1;
    requires ((k) <= 2000000000);
    requires ((k) <= (a) + (b) + (c));
    ensures \result == (a >= k);
*/
_Bool func(int a, int b, int c, int k)
{
    int cnt;
    int na;
    int nk;
    int nb;
    int nc;

    cnt = 0;
    //@ assert cnt == 0;

    if (a < k)
        na = a;
    else
        na = k;
    //@ assert na == (a < k ? a : k);

    cnt += na;
    //@ assert cnt == na;

    nk = k - na;
    //@ assert nk == k - na;

    if (b < nk)
        nb = b;
    else
        nb = nk;
    //@ assert nb == (b < nk ? b : nk);

    cnt += nb;
    //@ assert cnt == na + nb;

    nk = nk - nb;
    //@ assert nk == k - na - nb;

    if (c < nk)
        nc = c;
    else
        nc = nk;
    //@ assert nc == (c < nk ? c : nk);

    cnt += nc;
    //@ assert cnt == na + nb + nc;
    //@ assert cnt == k;

    return a >= k;
}
