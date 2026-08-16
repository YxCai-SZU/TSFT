#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((l_vec) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (l_vec)[i] >= 1 && (l_vec)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= n + 1;
*/
int func(int n, int x, const int *l_vec) {
    int d = 0;
    int count = 0;
    int index = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
    (d) >= 0 && (d) <= (x) + 100 &&
    (count) >= 0 && (count) <= (index) &&
    ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (l_vec)[i] >= 1 && (l_vec)[i] <= 100));
        loop assigns d, count, index;
        loop variant n - index;
    */
    while (d <= x && index < n) {
        //@ assert count >= 0 && count <= index;
        count += 1;
        //@ assert d >= 0 && d <= x + 100;
        d += l_vec[index];
        //@ assert index >= 0 && index < n;
        index += 1;
    }
    
    //@ assert count >= 0 && count <= n + 1;
    return count;
}
