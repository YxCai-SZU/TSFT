#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0 && \result <= 4;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int cnt = 0;
    int min_value;

    if (a >= b) {
        cnt += 1;
    }
    if (a >= c) {
        cnt += 1;
    }
    if (a >= d) {
        cnt += 1;
    }

    //@ assert cnt >= 0 && cnt <= 3;
    
    if (cnt < 4) {
        min_value = cnt;
    } else {
        min_value = 4;
    }

    //@ assert min_value >= 0;
    //@ assert min_value <= 4;
    
    return min_value;
}
