#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x >= 2000 || (100 * (x / 100) == x && x / 100 <= 13 * 8));
*/
bool func(int x) {
    int n;
    int temp_x;
    int hundred;
    int m;
    int temp_n;
    int m13;
    bool result;
    
    n = 0;
    temp_x = x;
    hundred = 100;
    
    /*@
        loop invariant (1 <= (x) <= 100000 &&
        0 <= (n) &&
        (hundred) > 0 &&
        (temp_x) >= 0 &&
        (x) == (temp_x) + (hundred) * (n));
        loop assigns temp_x, n;
        loop variant temp_x;
    */
    while (temp_x >= hundred) {
        //@ assert temp_x >= hundred && hundred > 0;
        temp_x -= hundred;
        n += 1;
    }
    
    n = n * hundred;
    
    if (x >= 2000) {
        result = true;
        return result;
    } else if (n == x) {
        m = 0;
        temp_n = n;
        
        /*@
            loop invariant (0 <= (m) &&
        (hundred) > 0 &&
        (temp_n) >= 0 &&
        (n) == (temp_n) + (hundred) * (m));
            loop assigns temp_n, m;
            loop variant temp_n;
        */
        while (temp_n >= hundred) {
            //@ assert temp_n >= hundred && hundred > 0;
            temp_n -= hundred;
            m += 1;
        }
        
        m13 = 13 * 8;
        
        if (m <= m13) {
            result = true;
            return result;
        } else {
            result = false;
            return result;
        }
    } else {
        result = false;
        return result;
    }
}
