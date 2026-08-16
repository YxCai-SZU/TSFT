#include <limits.h>

/*@
    requires (400 <= (X) && (X) < 2000);
    ensures \result == 10 - (X / 200);
*/
int func(int X) {
    int result;
    int temp;
    int count;
    
    result = 0;
    temp = X;
    count = 0;
    
    /*@
        loop invariant (400 <= (X) && (X) < 2000);
        loop invariant ((temp) >= 0);
        loop invariant ((temp) == (X) - 200 * (count));
        loop invariant ((count) >= 0);
        loop assigns temp, count;
    */
    while (temp >= 200) {
        int old_temp = temp;
        int old_count = count;
        
        /*@ assert temp >= 200; */
        temp -= 200;
        /*@ assert temp == old_temp - 200; */
        count += 1;
        /*@ assert count == old_count + 1; */
    }
    
    result = 10 - count;
    
    if (result < 0) {
        /*@ assert result < 0; */
        result = -result;
    }
    
    return result;
}
