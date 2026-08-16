#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 100;
    requires x >= 1 && x <= 10000;
    requires \valid(lengths + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (lengths)[i] >= 1 && (lengths)[i] <= 100);
    ensures \result >= 1 && \result <= n + 1;
*/
int func(int n, int x, int *lengths) {
    int di = 0;
    int i = 0;
    
    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
      0 <= (di) && (di) <= 100 * (i) &&
      (x) >= 1 && (x) <= 10000);
        loop assigns i, di;
        loop variant n - i;
    */
    while (i < n) {
        int l = lengths[i];
        di += l;
        
        //@ assert di >= l;
        if (x < di) {
            //@ assert i + 1 >= 1;
            return i + 1;
        }
        i += 1;
    }
    
    //@ assert i == n;
    return n + 1;
}
