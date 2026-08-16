#include <stdbool.h>

/*@
    requires (\valid((a)) && \valid((a)+1) && \valid((a)+2) &&
        (a)[0] >= 1 && (a)[0] <= 13 &&
        (a)[1] >= 1 && (a)[1] <= 13 &&
        (a)[2] >= 1 && (a)[2] <= 13);
    ensures \result == ((((a[0]) + (a[1]) == (a[2])) ? 1 : (((a[1]) + (a[2]) == (a[0])) ? 1 : (((a[0]) + (a[2]) == (a[1])) ? 1 : 0))) == 1);
    assigns \nothing;
*/
bool func(int *a)
{
    bool result = false;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    //@ assert \valid(a) && \valid(a+1) && \valid(a+2);
    
    sum1 = a[0] + a[1];
    sum2 = a[1] + a[2];
    sum3 = a[0] + a[2];

    if (sum1 == a[2] || sum2 == a[0] || sum3 == a[1]) {
        result = true;
    }

    //@ assert result == ((((a[0]) + (a[1]) == (a[2])) ? 1 : (((a[1]) + (a[2]) == (a[0])) ? 1 : (((a[0]) + (a[2]) == (a[1])) ? 1 : 0))) == 1);
    return result;
}
