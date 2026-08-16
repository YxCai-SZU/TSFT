#include <limits.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 100000;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int func(int h1, int m1, int h2, int m2, int k) {
    int start;
    int end;
    int sleep_time;

    //@ assert ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    
    //@ assert end - start == h2 * 60 + m2 - h1 * 60 - m1;
    
    sleep_time = end - start - k;
    return sleep_time;
}
