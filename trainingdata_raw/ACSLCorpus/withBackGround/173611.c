#include <stdint.h>

/*@
    predicate max_of_three(integer a, integer b, integer c, integer m) =
        (a >= b && a >= c && m == a) ||
        (b >= a && b >= c && m == b) ||
        (c >= a && c >= b && m == c);

    logic integer water_value(integer a, integer b, integer c, integer m) =
        (3 * m - (a + b + c) < 0) ? (3 * m - (a + b + c)) : 0;

    lemma water_range:
        \forall integer a, b, c, m, w;
            1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 5000 &&
            max_of_three(a, b, c, m) && w == water_value(a, b, c, m) ==>
            -1 <= w <= 20000;
*/

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    ensures -1 <= \result <= 20000;
*/
int32_t func(uint16_t a, uint16_t b, uint16_t c)
{
    uint16_t max;
    int32_t l;
    int32_t water;

    //@ assert 1 <= a <= 5000;
    //@ assert 1 <= b <= 5000;
    //@ assert 1 <= c <= 5000;

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    //@ assert max_of_three(a, b, c, max);

    l = 3 * (int32_t)max - ((int32_t)a + (int32_t)b + (int32_t)c);
    
    if (l < 0)
    {
        water = l;
    }
    else
    {
        water = 0;
    }

    //@ assert water == water_value(a, b, c, max);

    if (water == 0)
    {
        //@ assert water == 0;
        return -1;
    }
    else
    {
        //@ assert water != 0;
        return water;
    }
}
