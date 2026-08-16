#include <stdbool.h>

/*@
    requires (\valid((a)) &&
        \valid((a)+1) &&
        \valid((a)+2) &&
        (a)[0] >= 1 && (a)[0] <= 100 &&
        (a)[1] >= 1 && (a)[1] <= 100 &&
        (a)[2] >= 1 && (a)[2] <= 100);
    ensures \result == true <==> ((a[0]) < (a[2]) && (a[1]) < (a[2]) && (a[0]) + (a[1]) > (a[2]));
    assigns \nothing;
*/
bool func(int* a)
{
    //@ assert \valid(a) && \valid(a+1) && \valid(a+2);
    //@ assert a[0] >= 1 && a[0] <= 100;
    //@ assert a[1] >= 1 && a[1] <= 100;
    //@ assert a[2] >= 1 && a[2] <= 100;
    
    if (a[0] < a[2] && a[1] < a[2] && a[0] + a[1] > a[2]) {
        return true;
    } else {
        return false;
    }
}
