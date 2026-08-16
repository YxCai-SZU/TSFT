#include <stdbool.h>

/*@
    requires 0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    requires 0 <= k && k <= 123;
    ensures \result == true <==> e - a <= k;
    ensures \result == false <==> e - a > k;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long max_val;
    long min_val;
    long diff;

    // Calculate max_val
    //@ assert (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    if (a > b)
    {
        if (a > c)
        {
            if (a > d)
            {
                if (a > e)
                {
                    max_val = a;
                }
                else
                {
                    max_val = e;
                }
            }
            else
            {
                if (d > e)
                {
                    max_val = d;
                }
                else
                {
                    max_val = e;
                }
            }
        }
        else
        {
            if (c > d)
            {
                if (c > e)
                {
                    max_val = c;
                }
                else
                {
                    max_val = e;
                }
            }
            else
            {
                if (d > e)
                {
                    max_val = d;
                }
                else
                {
                    max_val = e;
                }
            }
        }
    }
    else
    {
        if (b > c)
        {
            if (b > d)
            {
                if (b > e)
                {
                    max_val = b;
                }
                else
                {
                    max_val = e;
                }
            }
            else
            {
                if (d > e)
                {
                    max_val = d;
                }
                else
                {
                    max_val = e;
                }
            }
        }
        else
        {
            if (c > d)
            {
                if (c > e)
                {
                    max_val = c;
                }
                else
                {
                    max_val = e;
                }
            }
            else
            {
                if (d > e)
                {
                    max_val = d;
                }
                else
                {
                    max_val = e;
                }
            }
        }
    }

    // Calculate min_val
    //@ assert (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    if (a < b)
    {
        if (a < c)
        {
            if (a < d)
            {
                if (a < e)
                {
                    min_val = a;
                }
                else
                {
                    min_val = e;
                }
            }
            else
            {
                if (d < e)
                {
                    min_val = d;
                }
                else
                {
                    min_val = e;
                }
            }
        }
        else
        {
            if (c < d)
            {
                if (c < e)
                {
                    min_val = c;
                }
                else
                {
                    min_val = e;
                }
            }
            else
            {
                if (d < e)
                {
                    min_val = d;
                }
                else
                {
                    min_val = e;
                }
            }
        }
    }
    else
    {
        if (b < c)
        {
            if (b < d)
            {
                if (b < e)
                {
                    min_val = b;
                }
                else
                {
                    min_val = e;
                }
            }
            else
            {
                if (d < e)
                {
                    min_val = d;
                }
                else
                {
                    min_val = e;
                }
            }
        }
        else
        {
            if (c < d)
            {
                if (c < e)
                {
                    min_val = c;
                }
                else
                {
                    min_val = e;
                }
            }
            else
            {
                if (d < e)
                {
                    min_val = d;
                }
                else
                {
                    min_val = e;
                }
            }
        }
    }

    // Calculate diff
    //@ assert max_val == (((a) > (b)) ?             (((a) > (c)) ?                 (((a) > (d)) ?                     (((a) > (e)) ? (a) : (e)) :                     (((d) > (e)) ? (d) : (e))) :                 (((c) > (d)) ?                     (((c) > (e)) ? (c) : (e)) :                     (((d) > (e)) ? (d) : (e)))) :             (((b) > (c)) ?                 (((b) > (d)) ?                     (((b) > (e)) ? (b) : (e)) :                     (((d) > (e)) ? (d) : (e))) :                 (((c) > (d)) ?                     (((c) > (e)) ? (c) : (e)) :                     (((d) > (e)) ? (d) : (e)))));
    //@ assert min_val == (((a) < (b)) ?             (((a) < (c)) ?                 (((a) < (d)) ?                     (((a) < (e)) ? (a) : (e)) :                     (((d) < (e)) ? (d) : (e))) :                 (((c) < (d)) ?                     (((c) < (e)) ? (c) : (e)) :                     (((d) < (e)) ? (d) : (e)))) :             (((b) < (c)) ?                 (((b) < (d)) ?                     (((b) < (e)) ? (b) : (e)) :                     (((d) < (e)) ? (d) : (e))) :                 (((c) < (d)) ?                     (((c) < (e)) ? (c) : (e)) :                     (((d) < (e)) ? (d) : (e)))));
    diff = max_val - min_val;

    //@ assert diff == (((((a)) > ((b))) ?             ((((a)) > ((c))) ?                 ((((a)) > ((d))) ?                     ((((a)) > ((e))) ? ((a)) : ((e))) :                     ((((d)) > ((e))) ? ((d)) : ((e)))) :                 ((((c)) > ((d))) ?                     ((((c)) > ((e))) ? ((c)) : ((e))) :                     ((((d)) > ((e))) ? ((d)) : ((e))))) :             ((((b)) > ((c))) ?                 ((((b)) > ((d))) ?                     ((((b)) > ((e))) ? ((b)) : ((e))) :                     ((((d)) > ((e))) ? ((d)) : ((e)))) :                 ((((c)) > ((d))) ?                     ((((c)) > ((e))) ? ((c)) : ((e))) :                     ((((d)) > ((e))) ? ((d)) : ((e)))))) - ((((a)) < ((b))) ?             ((((a)) < ((c))) ?                 ((((a)) < ((d))) ?                     ((((a)) < ((e))) ? ((a)) : ((e))) :                     ((((d)) < ((e))) ? ((d)) : ((e)))) :                 ((((c)) < ((d))) ?                     ((((c)) < ((e))) ? ((c)) : ((e))) :                     ((((d)) < ((e))) ? ((d)) : ((e))))) :             ((((b)) < ((c))) ?                 ((((b)) < ((d))) ?                     ((((b)) < ((e))) ? ((b)) : ((e))) :                     ((((d)) < ((e))) ? ((d)) : ((e)))) :                 ((((c)) < ((d))) ?                     ((((c)) < ((e))) ? ((c)) : ((e))) :                     ((((d)) < ((e))) ? ((d)) : ((e)))))));
    //@ assert diff == max_val - min_val;

    if (diff <= k)
    {
        //@ assert diff <= k;
        //@ assert e - a <= k;
        return true;
    }
    else
    {
        //@ assert diff > k;
        //@ assert e - a > k;
        return false;
    }
}
