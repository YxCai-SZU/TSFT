/*@
    predicate in_range(integer v) = 0 <= v <= 100;

    logic integer sub(integer x, integer a) = x - a;
    logic integer sub2(integer t, integer b) = t - b;

    lemma check_lemma:
        \forall integer a, b, x, check, temp;
        in_range(a) && in_range(b) && in_range(x) &&
        temp == sub(x, a) &&
        (temp >= 0 ==> temp == sub2(temp, b)) &&
        check == (temp >= 0 && temp <= 0) ==>
        check == (sub(x, a) >= 0 && sub(x, a) <= b);
*/

#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (x - a >= 0 && x - a <= b);
*/
bool func(long a, long b, long x)
{
    bool check = false;
    long temp = 0;

    temp = x - a;
    //@ assert temp == x - a;

    if (temp >= 0)
    {
        temp = temp - b;
        //@ assert temp == x - a - b;

        if (temp <= 0)
        {
            check = true;
        }
    }

    //@ assert check == (x - a >= 0 && x - a <= b);
    return check;
}
