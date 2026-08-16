#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((m) * 2 + ((n) - 1) * 4);
    assigns \nothing;
*/
int func(int n, int m) {
    int res;
    int temp_n;
    int count;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    res = m * 2;
    temp_n = n - 1;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n - 1;
        loop invariant 0 <= count <= n - 1;
        loop invariant res == m * 2;
        loop invariant temp_n == n - 1 - count;
        loop invariant (1 <= (n) <= 20 && 1 <= (m) <= 20);
        loop assigns count, temp_n;
    */
    while (temp_n >= 1) {
        //@ assert temp_n >= 1;
        count = count + 1;
        temp_n = temp_n - 1;
        //@ assert temp_n == n - 1 - count;
    }
    
    //@ assert count == n - 1;
    res = res + count * 4;
    //@ assert res == ((m) * 2 + ((n) - 1) * 4);
    return res;
}
