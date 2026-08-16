#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> ((\result) >= 0 &&
        (\result) * 8 / 100 == (a) &&
        (\result) * 10 / 100 == (b));
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int i = 1;
    bool found = false;
    int ans = -1;

    /*@
        loop invariant ((1 <= ((a)) && ((a)) <= 100 &&
        1 <= ((b)) && ((b)) <= 100) &&
        1 <= (i) && (i) <= 1001 &&
        ((found) == true || (found) == false) &&
        ((ans) == -1 || ((found) && (((ans)) >= 0 &&
        ((ans)) * 8 / 100 == ((a)) &&
        ((ans)) * 10 / 100 == ((b))))) &&
        ((i) > 1 && !(found) ==> (ans) == -1));
        loop assigns i, found, ans;
        loop variant 1001 - i;
    */
    while (i <= 1000)
    {
        unsigned int eight_percent = (i * 8) / 100;
        unsigned int ten_percent = (i * 10) / 100;

        if (eight_percent == a && ten_percent == b)
        {
            ans = (int)i;
            found = true;
            break;
        }
        i += 1;
    }

    return ans;
}
