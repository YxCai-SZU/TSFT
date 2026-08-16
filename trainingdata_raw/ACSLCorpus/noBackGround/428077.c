#include <limits.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * 800 - ((((n)) / 15) * 200 + ((((n)) % 15) / 5) * 10));
    assigns \nothing;
*/
int func(int n) {
    int result;
    int count;
    int temp_n;
    
    //@ assert (1 <= (n) <= 100);
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= ((n) / 15);
        loop invariant temp_n == n - count * 15;
        loop invariant (1 <= (n) <= 100);
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15) {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
    }
    
    //@ assert temp_n == ((n) % 15);
    result = result - count * 200;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= (((n) % 15) / 5);
        loop invariant temp_n == ((n) % 15) - count * 5;
        loop invariant (1 <= (n) <= 100);
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 5) {
        //@ assert temp_n >= 5;
        count = count + 1;
        temp_n = temp_n - 5;
    }
    
    //@ assert temp_n == ((n) % 15) - (((n) % 15) / 5) * 5;
    result = result - count * 10;
    
    //@ assert result == ((n) * 800 - ((((n)) / 15) * 200 + ((((n)) % 15) / 5) * 10));
    return result;
}
