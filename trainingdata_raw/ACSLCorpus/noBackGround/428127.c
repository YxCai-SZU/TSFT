#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (c <= b && a <= d);
 */
bool func(int a, int b, int c, int d)
{
    bool should_turn_on_ac = false;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    if (c <= b && a <= d)
    {
        should_turn_on_ac = true;
    }

    //@ assert should_turn_on_ac == true <==> (c <= b && a <= d);

    return should_turn_on_ac;
}
