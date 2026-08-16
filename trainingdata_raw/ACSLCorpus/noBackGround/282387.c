/*@
    requires 1 <= n <= 1000000000000;
    ensures \result == (n % 200 == 0 || n % 200 == 50 || n % 200 == 100 || n % 200 == 150);
*/
_Bool func(unsigned long long n)
{
    unsigned long long modulo;
    _Bool result;

    modulo = n % 200;
    
    if (modulo == 50 || modulo == 100 || modulo == 150 || modulo == 0)
    {
        //@ assert ((modulo) == 50 || (modulo) == 100 || (modulo) == 150 || (modulo) == 0);
        result = 1;
    }
    else
    {
        //@ assert !((modulo) == 50 || (modulo) == 100 || (modulo) == 150 || (modulo) == 0);
        result = 0;
    }
    
    return result;
}
