#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 200000 &&
      \forall integer j; 0 <= j < (n) ==> -1000000000 <= (a)[j] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, const int* a) {
    int s = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= s <= (int)i;
        loop invariant n > 0 && n <= 200000;
        loop invariant ((n) > 0 && (n) <= 200000 &&
      \forall integer j; 0 <= j < (n) ==> -1000000000 <= (a)[j] <= 1000000000);
        loop assigns s, i;
        loop variant n - i;
    */
    while (i < n) {
        int num = a[i];
        
        //@ assert 0 <= s <= (int)i;
        
        if ((i & 1) == 0 && (num & 1) == 0) {
            s += 1;
        }
        i += 1;
    }
    
    //@ assert s >= 0;
    return s;
}
