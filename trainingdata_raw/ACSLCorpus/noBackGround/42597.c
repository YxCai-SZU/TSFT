#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
  ensures \result >= 0 && \result <= (int)n;
*/
int func(size_t n, int *a)
{
    int count = 0;
    size_t num = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= num <= n;
      loop invariant 0 <= index <= n;
      loop invariant count >= 0;
      loop invariant count <= (int)num;
      loop invariant count <= (int)index;
      loop invariant ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
      loop assigns count, num, index;
    */
    while (num < n && index < n) {
        int v = a[index];
        
        //@ assert v > 0 && v <= 1000;
        
        if ((v & 1) == 1 && (num & 1) == 0) {
            count += 1;
            
            //@ assert count >= 0;
            
            if (count == 3) {
                //@ assert num >= 0;
                return (int)num;
            }
        }
        
        num += 1;
        index += 1;
    }
    
    //@ assert num >= 0;
    return (int)num;
}
