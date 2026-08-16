#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) <= 100);
  requires (\valid((arr) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 100);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int *arr) {
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant (0 <= (index) <= (n) && 0 <= (count) <= (index));
      loop invariant (1 <= (n) <= 100);
      loop invariant (\valid((arr) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 100);
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int a = arr[index];
        int i = (int)index + 1;
        
        //@ assert i >= 1;
        //@ assert 1 <= a <= 100;
        
        if ((i & 1) == 1 && (a & 1) == 1) {
            count += 1;
        }
        
        //@ assert count >= 0;
        //@ assert count <= (int)index + 1;
        index += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
