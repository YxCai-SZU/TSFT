#include <limits.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;

    lemma max_ab_property:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> max_of_two(a, b) >= a && max_of_two(a, b) >= b;

    lemma max_bc_property:
        \forall integer b, c;
            in_range(b) && in_range(c) ==> max_of_two(b, c) >= b && max_of_two(b, c) >= c;

    lemma max_cd_property:
        \forall integer c, d;
            in_range(c) && in_range(d) ==> max_of_two(c, d) >= c && max_of_two(c, d) >= d;

    lemma max_bd_property:
        \forall integer b, d;
            in_range(b) && in_range(d) ==> max_of_two(b, d) >= b && max_of_two(b, d) >= d;

    lemma max_ac_property:
        \forall integer a, c;
            in_range(a) && in_range(c) ==> max_of_two(a, c) >= a && max_of_two(a, c) >= c;

    lemma max_ad_property:
        \forall integer a, d;
            in_range(a) && in_range(d) ==> max_of_two(a, d) >= a && max_of_two(a, d) >= d;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_bd;
    int max_ac;
    int max_ad;
    int result;

    max_ab = (a > b) ? a : b;
    //@ assert max_ab >= a && max_ab >= b;

    max_bc = (b > c) ? b : c;
    //@ assert max_bc >= b && max_bc >= c;

    max_cd = (c > d) ? c : d;
    //@ assert max_cd >= c && max_cd >= d;

    max_bd = (b > d) ? b : d;
    //@ assert max_bd >= b && max_bd >= d;

    max_ac = (a > c) ? a : c;
    //@ assert max_ac >= a && max_ac >= c;

    max_ad = (a > d) ? a : d;
    //@ assert max_ad >= a && max_ad >= d;

    if (max_ab > max_bc)
    {
        if (max_ab > max_cd)
        {
            if (max_ab > max_bd)
            {
                if (max_ab > max_ac)
                {
                    if (max_ab > max_ad)
                    {
                        result = max_ab;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
            else
            {
                if (max_bd > max_ac)
                {
                    if (max_bd > max_ad)
                    {
                        result = max_bd;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
        }
        else
        {
            if (max_cd > max_bd)
            {
                if (max_cd > max_ac)
                {
                    if (max_cd > max_ad)
                    {
                        result = max_cd;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
            else
            {
                if (max_bd > max_ac)
                {
                    if (max_bd > max_ad)
                    {
                        result = max_bd;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
        }
    }
    else
    {
        if (max_bc > max_cd)
        {
            if (max_bc > max_bd)
            {
                if (max_bc > max_ac)
                {
                    if (max_bc > max_ad)
                    {
                        result = max_bc;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
            else
            {
                if (max_bd > max_ac)
                {
                    if (max_bd > max_ad)
                    {
                        result = max_bd;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
        }
        else
        {
            if (max_cd > max_bd)
            {
                if (max_cd > max_ac)
                {
                    if (max_cd > max_ad)
                    {
                        result = max_cd;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
            else
            {
                if (max_bd > max_ac)
                {
                    if (max_bd > max_ad)
                    {
                        result = max_bd;
                    }
                    else
                    {
                        result = max_ad;
                    }
                }
                else
                {
                    result = max_ac;
                }
            }
        }
    }

    //@ assert result == a || result == b || result == c || result == d;
    //@ assert result >= a && result >= b && result >= c && result >= d;
    return result;
}
