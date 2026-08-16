#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(int val) = 1 <= val <= 100; */

/*@ predicate array_valid(int* arr, integer len) =
    len == 3 &&
    \valid(arr + (0 .. len-1)) &&
    valid_range(arr[0]) &&
    valid_range(arr[1]) &&
    valid_range(arr[2]); */

/*@
  lemma count_bound:
    \forall integer count, integer index;
      1 <= count <= index && index <= 3 ==> count <= 3;
*/

/*@
  requires array_valid(v, 3);
  ensures \result <= 3;
  assigns \nothing;
*/
int func(int* v) {
    int min;
    int index;
    int count;
    
    //@ assert array_valid(v, 3);
    
    min = v[0];
    index = 1;
    count = 1;
    
    /*@
      loop invariant 0 <= index <= 3;
      loop invariant 1 <= count <= index;
      loop invariant index > 0 ==> \forall integer k; 0 <= k < index ==> min <= v[k];
      loop invariant \forall integer k; 0 <= k < 3 ==> 1 <= v[k] && v[k] <= 100;
      loop invariant array_valid(v, 3);
      loop assigns min, index, count;
      loop variant 3 - index;
    */
    while (index < 3) {
        //@ assert 0 <= index < 3;
        
        if (min > v[index]) {
            min = v[index];
            count = count + 1;
        }
        index = index + 1;
    }
    
    //@ assert count <= 3;
    return count;
}
