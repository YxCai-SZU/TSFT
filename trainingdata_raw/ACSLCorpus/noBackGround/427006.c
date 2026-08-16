#include <stdbool.h>

/*@
    requires a <= 4294967295;
    requires b <= 4294967295;
    requires c <= 4294967295;
    requires d <= 4294967295;
    ensures \result == true <==> ((a) < (b) && (c) < (d));
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool ans;
    ans = true;
    //@ assert ans == true;
    ans = ans && a < b;
    //@ assert ans == true <==> a < b;
    ans = ans && c < d;
    //@ assert ans == true <==> (a < b && c < d);
    return ans;
}
