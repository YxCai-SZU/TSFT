/*@
    requires 1 <= k <= 200000;
    ensures \result == (k % 200 == 0 || k % 200 < 105 || (k % 200 - 105) % 2 == 0);
*/
_Bool func(unsigned int k)
{
    unsigned int r;
    unsigned int tmp;
    _Bool result;

    r = k % 200;
    //@ assert r == k % 200;

    if (r == 0)
    {
        result = 1;
        //@ assert result == (k % 200 == 0 || k % 200 < 105 || (k % 200 - 105) % 2 == 0);
        return result;
    }
    else if (r < 105)
    {
        result = 1;
        //@ assert result == (k % 200 == 0 || k % 200 < 105 || (k % 200 - 105) % 2 == 0);
        return result;
    }
    else
    {
        tmp = r - 105;
        if (tmp % 2 == 0)
        {
            result = 1;
            //@ assert result == (k % 200 == 0 || k % 200 < 105 || (k % 200 - 105) % 2 == 0);
            return result;
        }
        else
        {
            result = 0;
            //@ assert k % 200 != 0 && k % 200 >= 105 && (k % 200 - 105) % 2 != 0;
            //@ assert result == (k % 200 == 0 || k % 200 < 105 || (k % 200 - 105) % 2 == 0);
            return result;
        }
    }
}
