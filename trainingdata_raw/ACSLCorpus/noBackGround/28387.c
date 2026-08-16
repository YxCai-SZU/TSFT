#include <limits.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -1 * c && \result <= 1 * a;
*/
int func(int a, int b, int c, int k)
{
    int k_mut = k;
    int min_a;
    int min_b;
    int min_c;
    int ans;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100 &&         1 <= (k) && (k) <= 100 &&         (a) + (b) + (c) >= (k));
    
    if (a < k_mut) {
        min_a = a;
    } else {
        min_a = k_mut;
    }
    k_mut -= min_a;
    
    if (b < k_mut) {
        min_b = b;
    } else {
        min_b = k_mut;
    }
    k_mut -= min_b;
    
    if (c < k_mut) {
        min_c = c;
    } else {
        min_c = k_mut;
    }
    k_mut -= min_c;
    
    ans = min_a - min_c;
    
    //@ assert ans >= -1 * c;
    
    return ans;
}
