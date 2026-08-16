#include <stdbool.h>

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == true <==> ((a < b && a < c && c < b) || (a > b && a > c && c > b));
    assigns \nothing;
 */
bool test1(int a, int b, int c)
{
    bool result;
    //@ assert (a < b && a < c && c < b) || (a > b && a > c && c > b) <==> ((a < b && a < c && c < b) || (a > b && a > c && c > b));
    result = (a < b && a < c && c < b) || (a > b && a > c && c > b);
    return result;
}
