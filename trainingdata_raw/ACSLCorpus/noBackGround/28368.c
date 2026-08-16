#include <stdbool.h>

/*@
  requires 2 <= n <= 100;
  requires 1 <= a <= n - 1;
  requires 1 <= b <= n - 1;
  requires a != b;
  ensures \result == true <==> ((a + b) % 2 == 0);
*/
bool func(int n, int a, int b) {
    bool is_even = false;
    int sum = a + b;
    int temp_sum = sum;
    int count = 0;

    /*@
      loop invariant 0 <= temp_sum <= sum;
      loop invariant 0 <= count <= sum / 2;
      loop invariant temp_sum == sum - 2 * count;
      loop assigns temp_sum, count;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
        count += 1;
    }
    
    if (temp_sum == 0) {
        is_even = true;
    }

    //@ assert is_even == true <==> ((a + b) % 2 == 0);
    return is_even;
}
