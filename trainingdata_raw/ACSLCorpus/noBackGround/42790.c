#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int func(long n) {
    long a = 0;
    long b = 0;
    long temp_n = n;
    long remainder;
    long additional_a;
    long additional_b;
    int result;
    
    //@ assert (1 <= (n) && (n) <= 100000);
    
    if (n < 0) {
        temp_n = -n;
    }
    
    //@ assert temp_n >= 0;
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant temp_n >= 0;
        loop invariant a >= 0;
        loop invariant temp_n == n - 105 * a;
        loop assigns temp_n, a;
        loop variant temp_n;
    */
    while (temp_n >= 105) {
        //@ assert temp_n >= 105;
        temp_n -= 105;
        a += 1;
        //@ assert temp_n == n - 105 * a;
    }
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant temp_n >= 0;
        loop invariant a >= 0;
        loop invariant b >= 0;
        loop invariant temp_n == n - 105 * a - 5 * b;
        loop assigns temp_n, b;
        loop variant temp_n;
    */
    while (temp_n >= 5) {
        //@ assert temp_n >= 5;
        temp_n -= 5;
        b += 1;
        //@ assert temp_n == n - 105 * a - 5 * b;
    }
    
    remainder = temp_n;
    
    //@ assert remainder >= 0;
    //@ assert remainder == n - 105 * a - 5 * b;
    
    if (remainder == 0) {
        result = (a <= b) ? 1 : 0;
        //@ assert result == 1 || result == 0;
        return result;
    } else {
        additional_a = (remainder > 5) ? 1 : 0;
        additional_b = (remainder > 0) ? 1 : 0;
        result = (a + additional_a <= b + additional_b) ? 1 : 0;
        //@ assert result == 1 || result == 0;
        return result;
    }
}

int main() {
    return 0;
}
