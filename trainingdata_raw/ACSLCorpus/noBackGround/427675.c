#include <stdbool.h>

/*@
  requires \valid_read(a + (0..1));
  requires a[0] >= 1 && a[0] <= 12;
  requires a[1] >= 1 && a[1] <= 31;
  ensures (1 <= (\result) && (\result) <= 12);
  assigns \nothing;
*/
int func(const int a[2]) {
    int ans;
    
    if (a[0] > a[1]) {
        ans = a[0] - 1;
        //@ assert ans == a[0] - 1;
    } else {
        ans = a[0];
        //@ assert ans == a[0];
    }
    
    //@ assert (1 <= (ans) && (ans) <= 12);
    return ans;
}
