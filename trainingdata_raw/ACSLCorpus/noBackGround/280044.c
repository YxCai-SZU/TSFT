/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result <= 1;
    ensures \result == 1 ==> (n * 2 + 1) <= m;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int res;

    if ((n * 2 + 1) <= m) {
        res = 1;
    } else {
        res = 0;
    }

    //@ assert res <= 1;
    //@ assert res == 1 ==> (n * 2 + 1) <= m;

    return res;
}
