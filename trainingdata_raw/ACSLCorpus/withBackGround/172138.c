#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    predicate result_properties(integer result, integer a, integer b) =
        result + a + b == 6 &&
        (result == 1 || result == 2 || result == 3);
*/

/*@
    requires valid_range(a, b);
    ensures result_properties(\result, a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    result = 6 - (a + b);

    //@ assert result == 1 || result == 2 || result == 3;
    if (result == 1 || result == 2 || result == 3)
    {
        return result;
    }
    else
    {
        //@ assert false;
        return 0;
    }
}

int main(void)
{
    return 0;
}
