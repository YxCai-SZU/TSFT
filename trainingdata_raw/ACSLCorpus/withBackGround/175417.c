#include <stdbool.h>

/*@
    predicate is_multiple_of_3(integer x) = x % 3 == 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int v[2];
    bool result[1];
    bool temp_result;

    v[0] = a;
    v[1] = b;

    //@ assert v[0] == a && v[1] == b;

    temp_result = (v[0] % 3 == 0) || (v[1] % 3 == 0) || ((v[0] + v[1]) % 3 == 0);
    //@ assert temp_result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);

    result[0] = temp_result;
    //@ assert result[0] == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);

    return result[0];
}
