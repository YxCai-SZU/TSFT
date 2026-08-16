#include <stdbool.h>

/*@
    predicate is_strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
 */

/*@
    lemma loop_invariant_holds:
        \forall integer a, b, c, i, answer;
        (0 <= i && i <= 3 &&
        0 <= a && a <= 100 &&
        0 <= b && b <= 100 &&
        0 <= c && c <= 100 &&
        (answer == true <==>
            (i == 0 ||
            (i == 1 && a < b) ||
            (i == 2 && a < b && b < c) ||
            (i == 3 && a < b && b < c)))) ==>
        (i == 3 ==> (answer == true <==> is_strictly_increasing(a, b, c)));
 */

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    ensures \result == true <==> a < b && b < c;
    ensures \result == false <==> !(a < b && b < c);
 */
bool func(int a, int b, int c)
{
    bool answer = true;
    int i = 0;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant 0 <= a <= 100;
        loop invariant 0 <= b <= 100;
        loop invariant 0 <= c <= 100;
        loop invariant answer == true <==>
            (i == 0 ||
            (i == 1 && a < b) ||
            (i == 2 && a < b && b < c) ||
            (i == 3 && a < b && b < c));
        loop assigns i, answer;
        loop variant 3 - i;
     */
    while (i < 3)
    {
        i = i + 1;

        if (i == 1)
        {
            //@ assert i == 1;
            if (a >= b)
            {
                answer = false;
            }
        }
        else if (i == 2)
        {
            //@ assert i == 2;
            if (b >= c)
            {
                answer = false;
            }
        }
        else if (i == 3)
        {
            //@ assert i == 3;
            if (a >= c)
            {
                answer = false;
            }
        }
    }

    //@ assert i == 3;
    //@ assert answer == true <==> is_strictly_increasing(a, b, c);
    return answer;
}
