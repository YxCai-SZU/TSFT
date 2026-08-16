/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
*/
_Bool func(int n)
{
    unsigned int n_abs;
    unsigned int div_result;
    unsigned int temp;
    unsigned int mod_result;
    _Bool result;

    //@ assert (10 <= (n) && (n) <= 99);
    n_abs = (n < 0) ? -n : n;

    div_result = 0;
    temp = n_abs;

    /*@
        loop invariant 0 <= temp <= n_abs;
        loop invariant div_result <= n_abs / 10;
        loop invariant temp == n_abs - 10 * div_result;
        loop assigns temp, div_result;
    */
    while (temp >= 10)
    {
        //@ assert temp >= 10;
        temp -= 10;
        div_result += 1;
        //@ assert temp == n_abs - 10 * div_result;
    }

    mod_result = temp;

    if (mod_result == 9 || div_result == 9)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result == (n % 10 == 9 || (n / 10) % 10 == 9);
    return result;
}
