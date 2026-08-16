#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures \result >= 1 && \result <= n;
*/
unsigned int func(unsigned int n, const unsigned int *p) {
    unsigned int cnt;
    unsigned int index;
    unsigned int a;
    
    cnt = 1;
    index = 1;
    a = p[0];
    
    /*@ loop invariant 1 <= index <= n;
        loop invariant cnt >= 1;
        loop invariant cnt <= index;
        loop assigns cnt, index, a;
    */
    while (index < n) {
        if (a > p[index]) {
            a = p[index];
            cnt = cnt + 1;
        }
        index = index + 1;
    }
    
    //@ assert cnt >= 1 && cnt <= n;
    
    return cnt;
}
