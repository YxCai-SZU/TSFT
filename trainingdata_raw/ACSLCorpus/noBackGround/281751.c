/*@
    requires 2 <= n <= 100;
    requires 1 <= a < b <= n;
    ensures \result == 1 <==> (b - a) % 2 == 0;
 */
int func(int n, int a, int b)
{
    int is_even = 0;
    int temp = b - a;

    /*@
        loop invariant 0 <= temp <= b - a;
        loop invariant (b - a) % 2 == 0 <==> temp % 2 == 0;
        loop assigns temp;
     */
    while (temp > 1)
    {
        //@ assert temp % 2 == 0 <==> (temp - 2) % 2 == 0;
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = 1;
    }

    //@ assert is_even == 1 <==> (b - a) % 2 == 0;
    return is_even;
}
