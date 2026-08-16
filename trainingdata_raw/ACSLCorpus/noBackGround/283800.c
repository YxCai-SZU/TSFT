#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 200000 &&
      \valid((p) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *p) {
    int cnt = 0;
    int index = 0;
    
    /*@ loop invariant (0 <= (index) <= (n) &&
      0 <= (cnt) <= (index) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \valid(((p)) + (0 .. ((n))-1)) &&
      (\forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n))) &&
      (\forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j])));
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        int i = p[index];
        if (i == index + 1) {
            cnt += 1;
        }
        index += 1;
    }
    
    int ans = (cnt >= 2) ? (cnt - 1) : 0;
    
    //@ assert ans >= 0;
    return ans;
}
