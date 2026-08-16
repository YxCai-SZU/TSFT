#include <stdbool.h>

/*@ predicate is_valid_range(integer n) = 1 <= n && n <= 100000; */
/*@ predicate is_valid_value(integer v) = 1 <= v && v <= 1000000000; */
/*@ predicate array_valid(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> is_valid_value(arr[i]); */

/*@
  requires is_valid_range(n);
  requires \valid(arr + (0 .. n-1));
  requires array_valid(arr, n);
  ensures 0 <= \result <= n;
  ensures array_valid(arr, n);
*/
int func(int n, int *arr) {
    int count = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant array_valid(arr, n);
      loop assigns count, index;
    */
    while (index < n) {
        int v1 = arr[index];
        int v2 = (index + 1 < n) ? arr[index + 1] : 0;
        int v3 = (index + 2 < n) ? arr[index + 2] : 0;
        
        //@ assert is_valid_value(v1);
        //@ assert index + 1 >= n || is_valid_value(v2);
        //@ assert index + 2 >= n || is_valid_value(v3);
        
        if ((v1 < v2 && v2 < v3) || (v1 > v2 && v2 > v3)) {
            count++;
            //@ assert count <= index + 1;
        }
        index++;
        //@ assert count <= index;
    }
    return count;
}
