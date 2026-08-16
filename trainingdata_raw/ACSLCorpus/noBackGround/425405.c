#include <stdbool.h>

/*@
  requires (\valid((numbers) + (0..2)) &&
      1 <= (numbers)[0] <= 9 &&
      1 <= (numbers)[1] <= 9 &&
      1 <= (numbers)[2] <= 9);
  ensures \result == ((((numbers[0]) * 100 + (numbers[1]) * 10 + (numbers[2])) % 4) == 0);
*/
bool func(int *numbers) {
    int sum;
    bool is_divisible;
    int abs_sum;
    
    //@ assert 1 <= numbers[0] <= 9;
    //@ assert 1 <= numbers[1] <= 9;
    //@ assert 1 <= numbers[2] <= 9;
    
    sum = numbers[0] * 100 + numbers[1] * 10 + numbers[2];
    is_divisible = false;
    
    if (sum < 0) {
        abs_sum = -sum;
    } else {
        abs_sum = sum;
    }
    
    /*@
      loop invariant 0 <= abs_sum <= 1000;
      loop invariant abs_sum <= sum;
      loop invariant (sum - abs_sum) % 4 == 0;
      loop assigns abs_sum;
    */
    while (abs_sum >= 4) {
        abs_sum -= 4;
    }
    
    if (abs_sum == 0) {
        is_divisible = true;
    }
    
    //@ assert is_divisible == ((sum % 4) == 0);
    return is_divisible;
}
