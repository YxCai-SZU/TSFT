#include <limits.h>
#include <stdbool.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h < 24 && 0 <= m && m < 60;

    predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        h1 < h2 || (h1 == h2 && m1 <= m2);

    logic integer time_diff(integer h1, integer m1, integer h2, integer m2) =
        (h1 == h2) ?
            ((m1 < m2) ? (m2 - m1) : (m1 - m2))
        :
            ((h2 * 60 + m2) - (h1 * 60 + m1));

    lemma diff_nonnegative:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) && time_order(h1, m1, h2, m2) ==>
            time_diff(h1, m1, h2, m2) >= 0;

    lemma diff_bound:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) && time_order(h1, m1, h2, m2) ==>
            time_diff(h1, m1, h2, m2) <= 60 * (h2 - h1) + m2 - m1;

    predicate is_valid_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;

    logic integer double_x(integer x) = x * 2;

    predicate condition_holds(integer x, integer y) =
        y >= double_x(x) && y % 2 == 0;
*/

int func_time(int h1, int m1, int h2, int m2, int k)
{
    int ans;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert k >= 0;
    //@ assert time_order(h1, m1, h2, m2);

    if (h1 == h2)
    {
        if (m1 < m2)
        {
            ans = m2 - m1;
        }
        else
        {
            ans = m1 - m2;
        }
    }
    else
    {
        int start_minutes = h1 * 60 + m1;
        int end_minutes = h2 * 60 + m2;
        ans = end_minutes - start_minutes;
    }

    ans = ans - k;

    //@ assert ans >= -k;
    //@ assert ans <= 60 * (h2 - h1) + m2 - m1;

    return ans;
}

bool func_valid(unsigned long X, unsigned long Y)
{
    unsigned long local_X = X;
    unsigned long local_Y = Y;
    bool result = false;

    //@ assert is_valid_range(local_X, local_Y);

    if (local_Y < local_X * 2)
    {
        result = false;
        //@ assert !(local_Y >= local_X * 2 && local_Y % 2 == 0);
        return result;
    }

    if (local_Y % 2 != 0)
    {
        result = false;
        //@ assert !(local_Y >= local_X * 2 && local_Y % 2 == 0);
        return result;
    }

    //@ assert local_Y >= local_X * 2 && local_Y % 2 == 0;
    result = true;
    return result;
}

bool schedule_validation(int h1, int m1, int h2, int m2, int k, unsigned long X, unsigned long Y)
{
    int adjusted_diff = func_time(h1, m1, h2, m2, k);
    
    //@ assert adjusted_diff >= -k;
    //@ assert adjusted_diff <= 60 * (h2 - h1) + m2 - m1;
    
    bool schedule_ok = func_valid(X, Y);
    
    //@ assert schedule_ok == (Y >= X * 2 && Y % 2 == 0);
    
    return schedule_ok;
}
