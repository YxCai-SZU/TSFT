/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) + (b) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int local_a = a;
    int local_b = b;
    int cnt = 0;

    if (c > local_a + local_b + 1)
    {
        cnt += local_a + local_b + 1;
    }
    else if (c > local_b)
    {
        cnt += local_b;
        local_a += local_b;
        //@ assert ((c - local_b) >= 0);
        if (c - local_b < local_a)
        {
            cnt += c - local_b;
        }
        else
        {
            cnt += local_a;
        }
    }
    else
    {
        cnt += c;
    }

    //@ assert cnt >= 0;
    return cnt;
}
