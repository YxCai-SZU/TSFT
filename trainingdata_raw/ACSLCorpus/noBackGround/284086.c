/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures ((\result) >= -1 && (\result) <= (n) + (m));
*/
int func(unsigned int n, unsigned int m)
{
    int result;
    unsigned int local_n;
    unsigned int local_m;

    local_n = n;
    local_m = m;

    if (local_n > 0 && local_m > 0)
    {
        if (local_n >= local_m)
        {
            local_n = local_n - local_m;
            local_m = 0;
            //@ assert 0 <= local_n + local_m <= n + m;
            result = (int)(local_n + local_m);
        }
        else
        {
            local_m = local_m - local_n;
            local_n = 0;
            //@ assert 0 <= local_n + local_m <= n + m;
            result = (int)(local_n + local_m);
        }
    }
    else
    {
        result = -1;
    }

    return result;
}
