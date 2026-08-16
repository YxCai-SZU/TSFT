#include <limits.h>

/*@
    requires (2 <= (k) <= 100);
    ensures \result == ((((k)) / 2) * ((k) - (((k)) / 2)));
    assigns \nothing;
*/
int func(int k) {
    int half_k;
    int count;
    int temp_k;
    
    //@ assert (2 <= (k) <= 100);
    
    if (k >= 0) {
        count = 0;
        temp_k = k;
        
        /*@
            loop invariant 0 <= temp_k <= k;
            loop invariant 0 <= count;
            loop invariant count <= ((k) / 2);
            loop invariant temp_k == k - 2 * count;
            loop invariant (2 <= (k) <= 100);
            loop assigns temp_k, count;
            loop variant temp_k;
        */
        while (temp_k >= 2) {
            //@ assert temp_k >= 2;
            temp_k = temp_k - 2;
            count = count + 1;
        }
        half_k = count;
    } else {
        count = 0;
        temp_k = k;
        
        /*@
            loop invariant k <= temp_k <= 0;
            loop invariant 0 <= count;
            loop invariant count <= -((k) / 2);
            loop invariant temp_k == k - 2 * count;
            loop invariant (2 <= (k) <= 100);
            loop assigns temp_k, count;
            loop variant -temp_k;
        */
        while (temp_k <= -2) {
            //@ assert temp_k <= -2;
            temp_k = temp_k + 2;
            count = count - 1;
        }
        half_k = count;
    }
    
    //@ assert 0 <= half_k <= 50;
    //@ assert 0 <= k - half_k <= 50;
    //@ assert 0 <= half_k * (k - half_k) <= 50 * 50;
    
    return half_k * (k - half_k);
}

int main() {
    return 0;
}
