#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_divisible_by_3_or_5(integer N, int *a) =
      \forall integer i; 0 <= i < N ==> 
        (a[i] % 2 == 0 ==> a[i] % 3 == 0 || a[i] % 5 == 0);
*/

/*@ lemma loop_invariant_maintains:
      \forall integer N, int *a, integer i;
        1 <= N && 0 <= i < N &&
        (\forall integer j; 0 <= j < i ==> 
          (a[j] % 2 == 0 ==> a[j] % 3 == 0 || a[j] % 5 == 0))
        ==>
        (a[i] % 2 != 0 || a[i] % 3 == 0 || a[i] % 5 == 0) ==>
          (\forall integer j; 0 <= j < i+1 ==> 
            (a[j] % 2 == 0 ==> a[j] % 3 == 0 || a[j] % 5 == 0));
*/

/*@
  requires N >= 1;
  requires \valid(a+(0..N-1));
  ensures \result == true <==> all_even_divisible_by_3_or_5(N, a);
  assigns \nothing;
*/
bool func(size_t N, int *a) {
    bool ans = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant ans == true <==> 
        \forall integer j; 0 <= j < i ==> 
          (a[j] % 2 == 0 ==> a[j] % 3 == 0 || a[j] % 5 == 0);
      loop assigns i, ans;
      loop variant N - i;
    */
    while (i < N) {
        int ai = a[i];
        
        if (ai % 2 != 0) {
            i++;
            continue;
        }
        
        if (!(ai % 3 == 0 || ai % 5 == 0)) {
            ans = false;
        }
        
        i++;
    }
    
    //@ assert ans == true <==> all_even_divisible_by_3_or_5(N, a);
    return ans;
}
