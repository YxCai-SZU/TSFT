#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n <= 100;
  requires \valid(v + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] <= 1000);
  ensures \result >= 0;
  ensures \result <= 1000 * n;
*/
int func(int n, int* v) {
    int count = 0;
    int i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (count) <= (i) &&
      \forall integer j; 0 <= j < (i) ==> 1 <= (v)[j] <= 1000 &&
      1 <= (n) <= 100 &&
      (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((v))[i] <= 1000));
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int a = v[i];
        int temp = a;
        
        /*@
          loop invariant temp >= 0 && temp <= a && temp % 2 == a % 2;
          loop assigns temp;
          loop variant temp;
        */
        while (temp >= 2 || temp <= -2) {
            if (temp > 0) {
                temp = temp - 2;
            } else {
                temp = temp + 2;
            }
        }
        
        bool is_even = (temp == 0);
        if (is_even) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
