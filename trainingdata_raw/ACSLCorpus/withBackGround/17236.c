#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer n) = (n % 2) == 0; */
/*@ predicate is_odd(integer n) = (n % 2) != 0; */

/*@
  requires 1 <= N <= 100;
  requires \valid(a + (0 .. N-1));
  requires \forall integer i; 0 <= i < N ==> 1 <= a[i] <= 1000;
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
int func(int N, const long long* a) {
    int count = 0;
    int num = 0;
    
    /*@
      loop invariant 0 <= num <= N;
      loop invariant 0 <= count <= num;
      loop invariant count <= num;
      loop assigns count, num;
      loop variant N - num;
    */
    while (num < N) {
        //@ assert 0 <= num < N;
        
        if ((num & 1) == 0) {
            long long value = a[num];
            
            //@ assert 1 <= value <= 1000;
            
            if ((value & 1) != 0) {
                //@ assert count + 1 <= num + 1;
                count += 1;
            }
        }
        num += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
