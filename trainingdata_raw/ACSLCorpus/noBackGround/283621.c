#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires ((n) >= 1 && (n) <= 1000000 &&
      \valid_read((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0 && \result <= (int)n;
*/
int func(size_t n, int64_t *a) {
    int64_t cur = 0;
    int cnt = 0;
    size_t i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
      (cnt) >= 0 && (cnt) <= (int)(i) &&
      \forall integer j; 0 <= j < (i) ==> (a)[j] >= 1 && (a)[j] <= 1000000000);
        loop assigns i, cnt, cur;
        loop variant n - i;
    */
    while (i < n) {
        int64_t ai = a[i];
        if (ai == cur) {
            cnt++;
        } else {
            cur = ai;
        }
        i++;
    }
    return cnt;
}
