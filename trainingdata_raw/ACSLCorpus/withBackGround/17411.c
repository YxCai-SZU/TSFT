#include <stdbool.h>

/*@
    predicate can_distribute(integer a, integer b, integer c) =
        (a + b == c || a + c == b || b + c == a) && (a != b || b != c || a != c);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> can_distribute(a, b, c);
 */
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum1;
    unsigned int sum2;
    unsigned int sum3;
    bool answer;

    sum1 = a + b;
    sum2 = a + c;
    sum3 = b + c;
    answer = false;

    if (sum1 == c || sum2 == b || sum3 == a)
    {
        if (a != b || b != c || a != c)
        {
            answer = true;
        }
        else
        {
            answer = false;
        }
    }
    else
    {
        answer = false;
    }

    //@ assert answer == true <==> can_distribute(a, b, c);
    return answer;
}
