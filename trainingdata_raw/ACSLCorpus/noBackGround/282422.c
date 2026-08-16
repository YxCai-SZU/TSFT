/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
*/
long func(long r)
{
    long pi_approx;
    long precision_factor;
    long product;
    long ans;
    long remainder;

    pi_approx = 314;
    precision_factor = 100;
    product = 2 * r * pi_approx;
    ans = 0;
    remainder = product;

    /*@
        loop invariant (0 <= (remainder) < (product) + (precision_factor) &&
        (ans) * (precision_factor) + (remainder) == (product) &&
        1 <= (r) <= 100 &&
        (pi_approx) == 314 &&
        (precision_factor) == 100 &&
        (product) == 2 * (r) * (pi_approx) &&
        (ans) * (precision_factor) + (remainder) == 2 * (r) * (pi_approx));
        loop assigns ans, remainder;
        loop variant remainder;
    */
    while (remainder >= precision_factor)
    {
        //@ assert ans * precision_factor + remainder == 2 * r * pi_approx;
        ans += 1;
        remainder -= precision_factor;
        //@ assert ans * precision_factor + remainder == 2 * r * pi_approx;
    }

    //@ assert ans * precision_factor + remainder == 2 * r * pi_approx;
    //@ assert ans * precision_factor + remainder == 2 * r * 314;
    //@ assert ans == 2 * r * 314 / 100;
    return ans;
}

int main()
{
    return 0;
}
