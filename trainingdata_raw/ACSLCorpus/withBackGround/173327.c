#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer p) =
        1 <= n <= 10000 && 1 <= p <= 10000;

    logic integer half_value(integer p) = p / 2;
    logic integer quarter_value(integer p) = p / 4;

    lemma half_definition:
        \forall integer p; 1 <= p <= 10000 ==>
            half_value(p) >= 0 && p - 2 * half_value(p) >= 0;

    lemma quarter_definition:
        \forall integer p; 1 <= p <= 10000 ==>
            quarter_value(p) >= 0 && p - 4 * quarter_value(p) >= 0;
*/

/*@
    requires valid_range(n, p);
    ensures \result == (n <= half_value(p) || n <= quarter_value(p) * 3);
*/
bool func(long n, long p)
{
    long half = 0;
    long quarter = 0;
    long temp = p;

    //@ assert valid_range(n, p);
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 1 <= p <= 10000;
        loop invariant half >= 0;
        loop invariant temp >= 0;
        loop invariant temp == p - 2 * half;
        loop assigns temp, half;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        half += 1;
    }

    temp = p;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 1 <= p <= 10000;
        loop invariant quarter >= 0;
        loop invariant temp >= 0;
        loop invariant temp == p - 4 * quarter;
        loop assigns temp, quarter;
        loop variant temp;
    */
    while (temp >= 4)
    {
        temp -= 4;
        quarter += 1;
    }

    //@ assert half == half_value(p);
    //@ assert quarter == quarter_value(p);
    
    return n <= half || n <= quarter * 3;
}
