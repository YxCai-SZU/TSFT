#include <stdint.h>

/*@
    predicate in_range_400_599(integer x) = 400 <= x && x <= 599;
    predicate in_range_600_799(integer x) = 600 <= x && x <= 799;
    predicate in_range_800_999(integer x) = 800 <= x && x <= 999;
    predicate in_range_1000_1199(integer x) = 1000 <= x && x <= 1199;
    predicate in_range_1200_1399(integer x) = 1200 <= x && x <= 1399;
    predicate in_range_1400_1599(integer x) = 1400 <= x && x <= 1599;
    predicate in_range_1600_1799(integer x) = 1600 <= x && x <= 1799;
    predicate in_range_1800_1999(integer x) = 1800 <= x && x <= 1999;
*/

/*@
    requires 400 <= X && X <= 1999;
    ensures \result >= 1 && \result <= 8;
    ensures \result == 8 ==> 400 <= X && X <= 599;
    ensures \result == 7 ==> 600 <= X && X <= 799;
    ensures \result == 6 ==> 800 <= X && X <= 999;
    ensures \result == 5 ==> 1000 <= X && X <= 1199;
    ensures \result == 4 ==> 1200 <= X && X <= 1399;
    ensures \result == 3 ==> 1400 <= X && X <= 1599;
    ensures \result == 2 ==> 1600 <= X && X <= 1799;
    ensures \result == 1 ==> 1800 <= X && X <= 1999;
*/
int32_t func(int64_t X)
{
    int32_t result;

    if (400 <= X && X <= 599)
    {
        //@ assert in_range_400_599(X);
        result = 8;
    }
    else if (600 <= X && X <= 799)
    {
        //@ assert in_range_600_799(X);
        result = 7;
    }
    else if (800 <= X && X <= 999)
    {
        //@ assert in_range_800_999(X);
        result = 6;
    }
    else if (1000 <= X && X <= 1199)
    {
        //@ assert in_range_1000_1199(X);
        result = 5;
    }
    else if (1200 <= X && X <= 1399)
    {
        //@ assert in_range_1200_1399(X);
        result = 4;
    }
    else if (1400 <= X && X <= 1599)
    {
        //@ assert in_range_1400_1599(X);
        result = 3;
    }
    else if (1600 <= X && X <= 1799)
    {
        //@ assert in_range_1600_1799(X);
        result = 2;
    }
    else if (1800 <= X && X <= 1999)
    {
        //@ assert in_range_1800_1999(X);
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
