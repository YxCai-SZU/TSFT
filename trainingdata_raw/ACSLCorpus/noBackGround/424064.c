#include <limits.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100) && (-100 <= (d) && (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ac;
    int max_bd;
    int res;

    max_ab = (a > b) ? a : b;
    max_bc = (b > c) ? b : c;
    max_cd = (c > d) ? c : d;
    max_ac = (a > c) ? a : c;
    max_bd = (b > d) ? b : d;

    if (max_ab > max_bc)
    {
        if (max_ab > max_cd)
        {
            if (max_ab > max_ac)
            {
                //@ assert max_ab >= a && max_ab >= b && max_ab >= c && max_ab >= d;
                res = (max_ab > max_bd) ? max_ab : max_bd;
                return res;
            }
            else
            {
                //@ assert max_ac >= a && max_ac >= b && max_ac >= c && max_ac >= d;
                res = max_ac;
                return res;
            }
        }
        else
        {
            //@ assert max_cd >= a && max_cd >= b && max_cd >= c && max_cd >= d;
            res = max_cd;
            return res;
        }
    }
    else
    {
        if (max_bc > max_cd)
        {
            if (max_bc > max_ac)
            {
                //@ assert max_bc >= a && max_bc >= b && max_bc >= c && max_bc >= d;
                res = (max_bc > max_bd) ? max_bc : max_bd;
                return res;
            }
            else
            {
                //@ assert max_ac >= a && max_ac >= b && max_ac >= c && max_ac >= d;
                res = max_ac;
                return res;
            }
        }
        else
        {
            //@ assert max_cd >= a && max_cd >= b && max_cd >= c && max_cd >= d;
            res = max_cd;
            return res;
        }
    }
}
