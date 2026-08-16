/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= (n));
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int func(int n, int k)
{
    int result = 0;
    int i = k;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 1 <= k && k <= n;
        loop invariant k <= i && i <= n + 1;
        loop invariant result == i - k;
        loop invariant result >= 0;
        loop assigns result, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        //@ assert result == i - k;
        result += 1;
        i += 1;
        //@ assert result == i - k;
    }

    //@ assert result == n - k + 1;
    return result;
}

int main(void)
{
    return 0;
}
