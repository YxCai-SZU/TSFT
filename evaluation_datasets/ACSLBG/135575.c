#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(integer N) = 1 <= N <= 100; */
/*@ predicate is_valid_array(int *a, integer N) = 
      \forall integer i; 0 <= i < N ==> 1 <= a[i] <= 100; */

/*@ lemma loop_invariant_maintained:
      \forall integer N, int *a, integer index, integer num, integer count;
      is_valid_range(N) && is_valid_array(a, N) &&
      0 <= index <= N && 0 <= num <= N && 0 <= count <= num &&
      (index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= a[i] <= 100) &&
      index < N && num < N ==>
      0 <= index+1 <= N && 0 <= num+1 <= N && 0 <= count + (a[index] & 1) <= num+1 &&
      (index+1 > 0 ==> \forall integer i; 0 <= i < index+1 ==> 1 <= a[i] <= 100); */


int func(int N, int *a) {
    int count = 0;
    int num = 0;
    size_t index = 0;
    
    
    while (index < (size_t)N && num < N) {
        int val = a[index];
        //@ assert 1 <= val <= 100;
        
        if (val & 1) {
            count++;
        }
        num++;
        index++;
    }
    return count;
}
