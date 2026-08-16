#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      0 <= (count) <= (i) &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (a)[j] > 0 && (a)[j] <= 1000);
        loop invariant i <= n;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert value > 0 && value <= 1000;
        
        if (value & 1 != 0) {
            count += 1;
            //@ assert 0 <= count <= i+1;
        }
        i += 1;
    }
    return count;
}

int main() {
    return 0;
}
