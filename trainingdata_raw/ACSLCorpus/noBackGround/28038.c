#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (m) >= 1 && (m) <= 100000 &&
      \valid((array) + (0 .. (n)-1)) &&
      \valid((b) + (0 .. (m)-1)));
  ensures \result >= 0 && \result <= m;
  assigns \nothing;
*/
int func(int n, int m, int *array, int *b) {
    // Variable declarations at top of scope
    int cnt = 0;
    size_t index = 0;
    bool found;
    size_t array_index;
    int v;
    
    // Precondition
    //@ assert ((n) >= 1 && (n) <= 100000 &&       (m) >= 1 && (m) <= 100000 &&       \valid((array) + (0 .. (n)-1)) &&       \valid((b) + (0 .. (m)-1)));
    
    /*@ loop invariant ((index) >= 0 && (index) <= (m) &&
      (cnt) >= 0 && (cnt) <= (index) &&
      (cnt) <= (m));
        loop invariant ((n) >= 1 && (n) <= 100000 &&
      (m) >= 1 && (m) <= 100000 &&
      \valid((array) + (0 .. (n)-1)) &&
      \valid((b) + (0 .. (m)-1)));
        loop assigns cnt, index, found, array_index, v;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        v = b[index];
        found = false;
        array_index = 0;
        
        /*@ loop invariant ((array_index) >= 0 && (array_index) <= (n));
            loop invariant ((n) >= 1 && (n) <= 100000 &&
      (m) >= 1 && (m) <= 100000 &&
      \valid((array) + (0 .. (n)-1)) &&
      \valid((b) + (0 .. (m)-1)));
            loop assigns found, array_index;
            loop variant n - array_index;
        */
        while (array_index < (size_t)n) {
            if (array[array_index] == v) {
                found = true;
                break;
            }
            array_index++;
        }
        
        if (found) {
            cnt++;
            //@ assert cnt >= 0;
        }
        
        index++;
        //@ assert cnt <= index;
    }
    
    // Postcondition
    //@ assert cnt >= 0;
    //@ assert cnt <= m;
    
    return cnt;
}
