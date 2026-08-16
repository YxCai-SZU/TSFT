/*@
    requires (1 <= (k) <= 100000);
    ensures \result == (k * 500) / 1000;
    assigns \nothing;
*/
unsigned int func(unsigned int k)
{
    unsigned int ans;

    //@ assert (1 <= (k) <= 100000);
    ans = (k * 500) / 1000;
    //@ assert ans == (k * 500) / 1000;
    return ans;
}

int main()
{
    return 0;
}
