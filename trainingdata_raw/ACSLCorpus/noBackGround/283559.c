#include <stdbool.h>

void test_animal(void)
{
    int big_bird_tag;
    int big_bird_wing_span;
    bool result;

    big_bird_tag = 1;
    big_bird_wing_span = 70;
    //@ assert ((big_bird_tag) == 1 && (big_bird_wing_span) > 60);
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == (a > 40 && b < 60);
*/
bool logic_multiple_conditions(int a, int b)
{
    bool result;

    //@ assert 0 <= a <= 100 && 0 <= b <= 100;
    result = (a > 40) && (b < 60);
    return result;
}
