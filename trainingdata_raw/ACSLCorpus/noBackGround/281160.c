/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> a > b + c + d;
*/
int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at the top
    int res;

    if (a > b + c + d)
    {
        //@ assert a > b + c + d;
        res = 1;
    }
    else
    {
        //@ assert !(a > b + c + d);
        res = 0;
    }

    return res;
}
