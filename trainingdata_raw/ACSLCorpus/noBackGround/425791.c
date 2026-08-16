#include <stdbool.h>

/*@
    requires (0 <= (n) <= 100 && 0 <= (x) <= (n) * 3);
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int x) {
    int count = 0;
    int temp_x = x;
    
    /*@
        loop invariant 0 <= count <= n;
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - 3 * count;
        loop assigns count, temp_x;
    */
    while (temp_x >= 3 && count < n) {
        //@ assert temp_x >= 3;
        temp_x -= 3;
        //@ assert temp_x >= 0;
        count += 1;
        //@ assert count <= n;
    }
    
    //@ assert count >= 0;
    return count;
}
