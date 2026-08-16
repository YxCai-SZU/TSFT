#include <stdbool.h>
#include <stddef.h>

/*@
requires n > 0 && n <= 100;
requires \valid(a + (0 .. n-1));
requires ((n) > 0 && (n) <= 100 &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
assigns \nothing;
ensures 0 <= \result <= n;
*/
int func(int n, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@
    loop invariant 0 <= num <= n;
    loop invariant 0 <= count <= num;
    loop invariant ((n) > 0 && (n) <= 100 &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    loop assigns count, num;
    loop variant n - num;
    */
    while (num < (size_t)n) {
        int ai = a[num];
        int r = (int)num + 1 - ai;
        
        //@ assert r >= 0 ==> count + 1 <= num + 1;
        if (r >= 0) {
            count += 1;
        }
        num += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
