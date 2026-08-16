#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    (len) >= 0 &&
    (\forall integer i; 0 <= i < (n) ==> (ls)[i] >= 1 && (ls)[i] <= 100));
    requires n <= len;
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int x, int* ls, int len) {
    int di = 0;
    int count = 0;
    int i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
    (di) >= 0 && (di) <= (i) * 100 &&
    (count) >= 0 && (count) <= (i) &&
    (\forall integer j; 0 <= j < (i) ==> (ls)[j] >= 1 && (ls)[j] <= 100));
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= x <= 10000;
        loop assigns di, count, i;
        loop variant n - i;
    */
    while (i < len && i < n) {
        int l = ls[i];
        di += l;
        //@ assert di >= 0 && di <= (i + 1) * 100;
        if (di <= x) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
