#include <limits.h>

/*@
    requires (1 <= (n) <= 100) && (1 <= (m) <= 100);
    requires (-100 <= (n) <= 100) && (-100 <= (m) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int sum;
    int max_val;

    sum = n + m;
    
    if (sum > 0) {
        max_val = sum;
        //@ assert max_val == sum;
    } else {
        max_val = 0;
        //@ assert max_val == 0;
    }
    
    //@ assert max_val >= 0;
    return max_val;
}
