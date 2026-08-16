/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result == 1 <==> ((((n)) * 2) <= (m) && (m) % 2 == 0);
    assigns \nothing;
*/
_Bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    _Bool result;

    //@ assert n * 2 <= 200;
    //@ assert m % 2 == m % 2;

    if (n * 2 <= m && m % 2 == 0)
    {
        //@ assert ((n) * 2) <= m && m % 2 == 0;
        result = 1;
    }
    else
    {
        //@ assert !(((n) * 2) <= m && m % 2 == 0);
        result = 0;
    }

    return result;
}
