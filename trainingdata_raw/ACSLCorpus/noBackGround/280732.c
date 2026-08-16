#include <stdbool.h>

/*@
  requires (1 <= (r) && (r) <= 9 &&
      1 <= (g) && (g) <= 9 &&
      1 <= (b) && (b) <= 9);
  ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
*/
bool func(int r, int g, int b) {
    int sum;
    int temp_sum;
    
    sum = r * 100 + g * 10 + b;
    temp_sum = sum;
    
    /*@
      loop invariant 1 <= r && r <= 9;
      loop invariant 1 <= g && g <= 9;
      loop invariant 1 <= b && b <= 9;
      loop invariant 0 <= temp_sum <= ((r) * 100 + (g) * 10 + (b));
      loop invariant temp_sum % 4 == ((r) * 100 + (g) * 10 + (b)) % 4;
      loop assigns temp_sum;
      loop variant temp_sum;
    */
    while (temp_sum >= 4) {
        temp_sum -= 4;
    }
    
    //@ assert temp_sum == ((r) * 100 + (g) * 10 + (b)) % 4;
    
    sum = temp_sum;
    
    if (sum == 0) {
        return true;
    } else {
        return false;
    }
}
