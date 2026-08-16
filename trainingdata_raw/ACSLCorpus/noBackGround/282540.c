#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) <= 100);
  requires \valid(a + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> (1 <= (a[i]) <= 100);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= n;
  ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> ((a[i]) % 2 == 0 || (a[i]) % 3 == 0 || (a[i]) % 5 == 0);
*/
int func(size_t n, const int a[]) {
    size_t i = 0;
    int num = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= num <= (int)i;
      loop invariant \forall integer j; 0 <= j < i ==> (1 <= (a[j]) <= 100);
      loop invariant \forall integer j; 0 <= j < i ==> !((a[j]) % 2 == 0 || (a[j]) % 3 == 0 || (a[j]) % 5 == 0) ==> num > 0;
      loop invariant i > 0 ==> \forall integer j; 0 <= j < i ==> ((a[j]) % 2 == 0 || (a[j]) % 3 == 0 || (a[j]) % 5 == 0);
      loop invariant (1 <= (n) <= 100);
      loop invariant \forall integer k; 0 <= k < n ==> (1 <= (a[k]) <= 100);
      loop assigns i, num;
    */
    while (i < n) {
        int s = a[i];
        //@ assert (1 <= (s) <= 100);
        if (!(s % 2 == 0 || s % 3 == 0 || s % 5 == 0)) {
            return num;
        }
        i += 1;
        num += 1;
    }
    return -1;
}
