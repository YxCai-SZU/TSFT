#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((((a) + (b)) % 2) == 0 && (((c) + (d)) % 2) == 0);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d) {
    int a1, b1, c1, d1;
    bool is_even1, is_even2;
    int sum1, sum2;
    int temp_sum1, temp_sum2;
    
    // Sort pairs
    if (a > b) {
        a1 = b;
        b1 = a;
    } else {
        a1 = a;
        b1 = b;
    }
    
    if (c > d) {
        c1 = d;
        d1 = c;
    } else {
        c1 = c;
        d1 = d;
    }
    
    //@ assert (1 <= (a1) <= 10000) && (1 <= (b1) <= 10000) && (1 <= (c1) <= 10000) && (1 <= (d1) <= 10000);
    //@ assert a1 + b1 == a + b && c1 + d1 == c + d;
    
    is_even1 = false;
    is_even2 = false;
    
    sum1 = a1 + b1;
    sum2 = c1 + d1;
    
    // Check if sum1 is even
    temp_sum1 = sum1;
    /*@
        loop invariant 0 <= temp_sum1 <= sum1;
        loop invariant temp_sum1 % 2 == sum1 % 2;
        loop assigns temp_sum1;
        loop variant temp_sum1;
    */
    while (temp_sum1 >= 2) {
        temp_sum1 -= 2;
    }
    if (temp_sum1 == 0) {
        is_even1 = true;
    }
    
    // Check if sum2 is even
    temp_sum2 = sum2;
    /*@
        loop invariant 0 <= temp_sum2 <= sum2;
        loop invariant temp_sum2 % 2 == sum2 % 2;
        loop assigns temp_sum2;
        loop variant temp_sum2;
    */
    while (temp_sum2 >= 2) {
        temp_sum2 -= 2;
    }
    if (temp_sum2 == 0) {
        is_even2 = true;
    }
    
    //@ assert is_even1 == (sum1 % 2 == 0);
    //@ assert is_even2 == (sum2 % 2 == 0);
    
    return is_even1 && is_even2;
}
