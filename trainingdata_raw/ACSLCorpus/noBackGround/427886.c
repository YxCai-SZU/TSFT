/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
_Bool func(int k, int x)
{
    int sum;
    //@ assert 1 <= k <= 100 && 1 <= x <= 100000;
    sum = 500 * k;
    //@ assert sum == 500 * k;
    return sum >= x;
}
