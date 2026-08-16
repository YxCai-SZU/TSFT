#include <stdint.h>

/*@
    requires (2 <= (k) && (k) <= 100);
    ensures \result == ((((k)) / 2) * (((k)) - ((((k))) / 2)));
    assigns \nothing;
*/
int64_t func(int64_t k) {
    int64_t half_k;
    int64_t remainder;
    int64_t result;
    
    // Variable declarations for first branch
    int64_t count;
    int64_t temp_k;
    
    // Variable declarations for second branch
    int64_t count2;
    int64_t temp_k2;
    
    if (k >= 0) {
        count = 0;
        temp_k = k;
        
        /*@
            loop invariant 0 <= temp_k <= k;
            loop invariant 0 <= count <= ((k) / 2);
            loop invariant temp_k == k - 2 * count;
            loop invariant (2 <= (k) && (k) <= 100);
            loop assigns temp_k, count;
            loop variant temp_k;
        */
        while (temp_k >= 2) {
            temp_k -= 2;
            count += 1;
        }
        half_k = count;
    } else {
        count2 = 0;
        temp_k2 = k;
        
        /*@
            loop invariant k <= temp_k2 <= 0;
            loop invariant -((k) / 2) <= count2 <= 0;
            loop invariant temp_k2 == k - 2 * count2;
            loop invariant (2 <= (k) && (k) <= 100);
            loop assigns temp_k2, count2;
            loop variant -temp_k2;
        */
        while (temp_k2 <= -2) {
            temp_k2 += 2;
            count2 -= 1;
        }
        half_k = count2;
    }
    
    remainder = k - half_k;
    
    //@ assert 0 <= half_k <= 50;
    //@ assert 0 <= remainder <= 50;
    //@ assert 0 <= half_k * remainder <= 2500;
    //@ assert half_k * remainder == ((((k)) / 2) * (((k)) - ((((k))) / 2)));
    
    result = half_k * remainder;
    return result;
}

int main() {
    return 0;
}
