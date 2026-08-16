/*@
    requires 1 <= x <= 100;
    ensures \result == (x / 2) + (x % 2);
    ensures \result >= 1;
    ensures \result <= 50;
*/
unsigned int func(unsigned int x)
{
    unsigned int half;
    unsigned int remainder;
    unsigned int result;

    half = x / 2;
    remainder = x % 2;
    //@ assert half == x / 2;
    //@ assert remainder == x % 2;
    result = half + remainder;
    return result;
}

/*@
    requires 1 <= n <= 100;
    ensures \result == (n / 2) + (n % 2);
    ensures \result >= 1;
    ensures \result <= 50;
*/
unsigned int func_nonlinear(unsigned int n)
{
    unsigned int half;
    unsigned int remainder;
    unsigned int result;

    half = n / 2;
    remainder = n % 2;
    //@ assert half == n / 2 && remainder == n % 2;
    result = half + remainder;
    return result;
}
