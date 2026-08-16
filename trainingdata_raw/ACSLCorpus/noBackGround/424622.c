/*@
    requires (1 <= (x) && (x) <= 1000000000);
    ensures \result <= (2 * ((x) / 11) + ((x) % 11 + 10) / 6);
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned long func(unsigned long x)
{
    unsigned long ans;
    unsigned long rem;

    ans = (x / 11) * 2;
    rem = x % 11;

    if (rem > 0)
    {
        ans += 1;
        if (rem > 5)
        {
            ans += 1;
        }
    }

    //@ assert ans <= (2 * ((x) / 11) + ((x) % 11 + 10) / 6);
    //@ assert ans >= 0;

    return ans;
}
