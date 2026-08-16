#include <stdbool.h>

/*@
  requires \valid(a + (0..1));
  requires (1 <= (a[0]) && (a[0]) <= 12) && (1 <= (a[1]) && (a[1]) <= 31);
  ensures (1 <= (\result) && (\result) <= 12);
  ensures \result == 1 || \result == a[0];
*/
int func(int a[2]) {
    int result;
    
    //@ assert (1 <= (a[0]) && (a[0]) <= 12) && (1 <= (a[1]) && (a[1]) <= 31);
    
    if (a[0] == 12 && a[1] >= 13) {
        result = 1;
    } else {
        result = a[0];
    }
    
    //@ assert (1 <= (result) && (result) <= 12);
    //@ assert result == 1 || result == a[0];
    
    return result;
}
