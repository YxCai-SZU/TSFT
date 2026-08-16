/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) * (m) - ((n) - 1) - (m) + 1);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int product;
    int result;

    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    //@ assert 1 <= n * m <= 10000;
    product = n * m;
    //@ assert product == n * m;
    //@ assert product >= 1 && product <= 10000;

    result = product - (n - 1) - m + 1;
    //@ assert result == ((n) * (m) - ((n) - 1) - (m) + 1);
    //@ assert result >= 1;

    return result;
}
