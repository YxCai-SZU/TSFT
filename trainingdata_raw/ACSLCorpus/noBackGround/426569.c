#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> (aa)[i] >= 1 && (aa)[i] <= 100);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *aa) {
    int an = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
      (an) >= 0 && (an) <= (int)(i) &&
      (((n)) >= 1 && ((n)) <= 100 &&
      \forall size_t i; 0 <= i < ((n)) ==> ((aa))[i] >= 1 && ((aa))[i] <= 100));
        loop assigns i, an;
        loop variant n - i;
    */
    while (i < n) {
        int a = aa[i];
        if (a & 1) {
            an += 1;
        }
        i += 1;
    }
    
    //@ assert an >= 0;
    //@ assert an <= (int)n;
    return an;
}
