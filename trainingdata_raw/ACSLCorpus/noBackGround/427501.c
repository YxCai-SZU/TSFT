#include <limits.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) % 2 == 0) ? ((x) / 2) : ((x) / 2 + 1));
    assigns \nothing;
*/
int func(int x) {
    int ans;
    int temp_x;
    int count;
    
    ans = 0;
    temp_x = x;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= x / 2;
        loop invariant temp_x == x - 2 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2) {
        //@ assert temp_x >= 2;
        temp_x -= 2;
        count += 1;
    }
    
    if (temp_x == 1) {
        //@ assert temp_x == 1;
        ans = count + 1;
    } else {
        //@ assert temp_x == 0;
        ans = count;
    }
    
    //@ assert ans == (((x) % 2 == 0) ? ((x) / 2) : ((x) / 2 + 1));
    return ans;
}
