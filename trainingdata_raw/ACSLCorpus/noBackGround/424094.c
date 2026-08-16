#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result >= 0 && \result <= 50;
    assigns \nothing;
*/
int func(int n, int m) {
    int result;
    int temp_n;
    int temp_m;
    int count;
    int min_val;
    int max_val;
    int max_val2;
    
    result = 0;
    temp_n = n;
    temp_m = m;
    count = 0;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    min_val = n < m ? n : m;
    
    /*@
        loop invariant 0 <= count <= min_val;
        loop invariant temp_n == n - 2 * count;
        loop invariant temp_m == m - count;
        loop invariant (1 <= (n) <= 20 && 1 <= (m) <= 20);
        loop assigns count, temp_n, temp_m;
        loop variant min_val - count;
    */
    while (count < min_val) {
        //@ assert count < min_val;
        temp_n = temp_n - 2;
        temp_m = temp_m - 1;
        count = count + 1;
        //@ assert count <= min_val;
    }
    
    max_val = temp_n > temp_m ? temp_n : temp_m;
    
    result = count + max_val;
    
    max_val2 = result > 0 ? result : 0;
    
    //@ assert max_val2 >= 0;
    
    //@ assert max_val2 <= 50;
    
    return max_val2;
}
