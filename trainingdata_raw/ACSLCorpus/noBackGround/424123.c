#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500 &&
      \valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  ensures ((\result) >= 0 && (\result) <= (n));
  ensures (\forall integer i; 0 <= i < (n) ==> ((h)[i] >= (k) ==> (\result) > 0));
  ensures (\forall integer i; 0 <= i < (n) ==> ((h)[i] < (k) ==> (\result) < (n)));
*/
int func(int n, int k, int *h)
{
    int sum = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant sum >= 0;
        loop invariant sum <= index;
        loop invariant \forall integer i; 0 <= i < index ==> h[i] >= 1 && h[i] <= 500;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (h[i] >= k ==> sum > 0);
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (h[i] < k ==> sum < index);
        loop assigns sum, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            sum += 1;
        }
        index += 1;
    }
    return sum;
}
