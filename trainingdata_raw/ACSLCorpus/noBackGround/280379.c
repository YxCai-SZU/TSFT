#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= (int)(n));
    assigns \nothing;
    ensures \result >= -1;
    ensures \result <= (int)n-1;
*/
int func(size_t n, int *a) {
    bool has_last = false;
    size_t last_value = 0;
    int count = 0;
    size_t i = 0;

    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
      0 <= (count) && (count) <= (int)(i) &&
      \forall integer j; 0 <= j < (i) ==> (a)[j] > 0 && (a)[j] <= (int)(n));
        loop invariant has_last ==> last_value > 0 && last_value <= n;
        loop invariant !has_last ==> count == 0;
        loop assigns i, count, last_value, has_last;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert value > 0 && value <= (int)n;
        
        if (!has_last || last_value != (size_t)value) {
            last_value = (size_t)value;
            has_last = true;
            count++;
        }
        //@ assert count <= (int)(i+1);
        i++;
    }
    
    //@ assert count <= (int)n;
    if (count < 3) {
        return -1;
    } else {
        return count - 2;
    }
}
