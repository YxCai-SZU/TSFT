#include <stdbool.h>

/*@
    predicate in_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;

    logic integer mod_two(integer n) = n % 2;

    lemma mod_property:
        \forall integer y, temp;
        temp >= 0 && temp <= y && mod_two(temp) == mod_two(y) && temp == 0 ==> mod_two(y) == 0;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (y >= x * 2 && y <= x * 4 && y % 2 == 0);
*/
bool func(int x, int y)
{
    bool condition;
    int temp;

    condition = true;
    condition = condition && (y >= x * 2 && y <= x * 4);

    temp = y;
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant temp >= 0;
        loop invariant temp <= y;
        loop invariant temp % 2 == y % 2;
        loop assigns temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    //@ assert temp % 2 == y % 2;
    condition = condition && (temp == 0);

    //@ assert condition == (y >= x * 2 && y <= x * 4 && y % 2 == 0);
    return condition;
}
