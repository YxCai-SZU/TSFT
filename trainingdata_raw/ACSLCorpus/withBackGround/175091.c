#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *arr, integer n) =
      n > 0 && n <= 20 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ predicate count_bounds(integer cnt, integer idx) =
      cnt >= 0 && cnt <= idx - 1;
*/

/*@ lemma index_bounds:
      \forall integer idx, integer n; 1 <= idx && idx <= n ==> idx - 1 >= 0;
*/

/*@
  requires n > 0 && n <= 20;
  requires \valid(h + (0 .. n-1));
  requires valid_array(h, n);
  assigns \nothing;
  ensures 0 <= \result <= n - 1;
*/
int func(int n, int *h) {
    int count = 0;
    int index = 1;
    
    /*@ loop invariant 1 <= index <= n;
        loop invariant 0 <= count <= index - 1;
        loop invariant valid_array(h, n);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int max = 0;
        int i = 0;
        
        /*@ loop invariant 0 <= i <= index;
            loop invariant \forall integer j; 0 <= j < i ==> h[j] <= max;
            loop invariant i == 0 ==> max == 0;
            loop invariant i > 0 ==> \exists integer j; 0 <= j < i && h[j] == max;
            loop assigns max, i;
            loop variant index - i;
        */
        while (i < index) {
            //@ assert 0 <= i < n;
            if (h[i] > max) {
                max = h[i];
            }
            i++;
        }
        
        //@ assert 0 <= index < n;
        if (max <= h[index]) {
            count++;
        }
        index++;
    }
    
    //@ assert 0 <= count <= n - 1;
    return count;
}
