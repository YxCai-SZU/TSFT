/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int func(int n, int a)
{
    int result;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 100;
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= a <= n * n;
        loop invariant i > 0 ==> n * n >= 0;
        loop invariant i < 101;
        loop assigns i;
        loop variant 100 - i;
    */
    while (i < 100)
    {
        i = i + 1;
    }
    
    //@ assert n * n <= 10000;
    
    result = n * n - a;
    return result;
}
