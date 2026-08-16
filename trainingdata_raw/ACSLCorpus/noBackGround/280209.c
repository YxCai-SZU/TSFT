#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 200000;
  requires \valid(a + (0 .. n-1));
  requires ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n));
  assigns \nothing;
  ensures \result >= -1 && \result <= n;
*/
int func(int n, int *a) {
    int search;
    size_t index;
    int count;
    int result;
    
    search = 1;
    index = 0;
    count = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 1 <= search <= n + 1;
        loop invariant 0 <= count <= index;
        loop invariant ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n));
        loop assigns search, index, count;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = a[index];
        
        if (i == search) {
            search++;
        } else {
            count++;
        }
        
        index++;
    }
    
    if (search == 1) {
        result = -1;
    } else {
        result = count;
    }
    
    return result;
}
