/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int a, unsigned int b)
{
    unsigned int ans;
    //@ assert 1 <= n <= 20;
    //@ assert 1 <= a <= 50;
    //@ assert n * a <= 1000;

    if (n * a < b)
    {
        ans = n * a;
    }
    else
    {
        ans = b;
    }
    return ans;
}

int main(void)
{
    return 0;
}
