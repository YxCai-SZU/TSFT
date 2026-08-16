/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
*/
int func(int r)
{
    // Variable declarations
    int pi;
    int ans;
    int result;
    int temp;
    int divisor;
    int count;

    // Initialization
    pi = 314;
    ans = 2 * r * pi;
    result = 0;
    temp = ans;
    divisor = 100;
    count = 0;

    /*@
        loop invariant (1 <= (r) && (r) <= 100);
        loop invariant pi == 314;
        loop invariant ((ans) == 2 * (r) * 314);
        loop invariant divisor == 100;
        loop invariant ((temp) >= 0 &&
        (ans) == (temp) + (result) * (divisor) &&
        (count) == ((ans) - (temp)) / (divisor) &&
        (count) * (divisor) + (temp) == (ans));
        loop assigns temp, result, count;
        loop variant ((temp));
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        result += 1;
        count += 1;
    }

    return result;
}
