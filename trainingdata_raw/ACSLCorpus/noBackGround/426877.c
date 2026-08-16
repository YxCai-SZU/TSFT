/*@
    requires (10 <= (N) && (N) <= 99);
    ensures \result == (N / 10 == 9 || N % 10 == 9);
*/
_Bool func(int N)
{
    int n;
    int a;
    int b;
    int count;

    n = N;
    a = 0;
    b = 0;
    count = 0;

    /*@
        loop invariant 10 <= N <= 99;
        loop invariant 0 <= n <= N;
        loop invariant a == (((N) - (n)) / 10);
        loop invariant count == (((N) - (n)) / 10);
        loop invariant n == ((N) - 10 * (count));
        loop invariant 0 <= count <= N / 10;
        loop assigns n, a, count;
    */
    while (n >= 10)
    {
        //@ assert n >= 10;
        n -= 10;
        a += 1;
        count += 1;
    }

    b = n;

    //@ assert a == N / 10;
    //@ assert b == N % 10;
    return (a == 9) || (b == 9);
}
