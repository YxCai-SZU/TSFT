/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) * (n)) / 4);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int res;
    unsigned int i;

    //@ assert (1 <= (n) && (n) <= 100);
    res = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant res == 0;
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        i = i + 1;
    }

    //@ assert n * n <= 10000;
    res = (n * n) / 4;
    return res;
}

int main(void)
{
    return 0;
}
