#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures (((\result) == ((((a)) * 2) - ((b))) || (\result) == 0) && (\result) >= 0);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    result = (a * 2) - b;
    if (result > 0) {
        //@ assert result == (((a) * 2) - (b));
        return result;
    } else {
        return 0;
    }
}

