#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    requires valid_range(z);
    ensures \result == (x * y < z);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= z <= 100;
    //@ assert x * y <= 10000;
    return x * y < z;
}

/*@
    lemma example_1: \forall integer x, y; x == y + 2 ==> x <= y + 2;
*/

/*@
    lemma example_2: \forall integer x, y; x == y + 2 ==> x == y + 1 + 1;
*/

/*@
    lemma example_3: \forall integer x, y; x == y + 2 ==> x <= y + 3;
*/

/*@
    lemma example_4: \forall integer x, y; x == y + 2 ==> x == y + 1 + 1;
*/

int main()
{
    return 0;
}
