/*@
    requires 100 <= n <= 999;
    ensures \result == (n / 100 == 7 || n / 10 % 10 == 7 || n % 10 == 7);
*/
_Bool func(int n)
{
    int num;
    _Bool ok;
    int cnt;
    int n_copy;
    int a;
    int b;
    int c;

    num = n;
    ok = 0;
    cnt = 0;
    n_copy = n;
    a = 0;
    b = 0;
    c = 0;

    /*@
        loop invariant 100 <= n <= 999;
        loop invariant 0 <= a <= n / 100;
        loop invariant n_copy == n - 100 * a;
        loop assigns n_copy, a;
    */
    while (n_copy >= 100)
    {
        n_copy -= 100;
        a += 1;
    }

    /*@
        loop invariant 100 <= n <= 999;
        loop invariant 0 <= a <= n / 100;
        loop invariant 0 <= b <= (n - 100 * a) / 10;
        loop invariant n_copy == n - 100 * a - 10 * b;
        loop assigns n_copy, b;
    */
    while (n_copy >= 10)
    {
        n_copy -= 10;
        b += 1;
    }

    c = n_copy;

    //@ assert ((a) == 7 || (b) == 7 || (c) == 7) ==> (a == 7 || b == 7 || c == 7);
    if (a == 7 || b == 7 || c == 7)
    {
        ok = 1;
    }

    //@ assert ok == (n / 100 == 7 || n / 10 % 10 == 7 || n % 10 == 7);
    return ok;
}
