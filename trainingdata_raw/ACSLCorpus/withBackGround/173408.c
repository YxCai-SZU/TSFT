#include <stdbool.h>

/*@ predicate is_valid_range(integer i) = 1 <= i && i <= 13; */

/*@
  requires \valid(numbers + (0..2));
  requires is_valid_range(numbers[0]) && is_valid_range(numbers[1]) && is_valid_range(numbers[2]);
  ensures \result == (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
*/
bool func(int numbers[3]) {
    bool ans;
    int n0;
    int n1;
    int n2;
    
    ans = false;
    n0 = numbers[0];
    n1 = numbers[1];
    n2 = numbers[2];
    
    //@ assert n1 - n0 >= -12 && n1 - n0 <= 12;
    //@ assert n2 - n1 >= -12 && n2 - n1 <= 12;
    
    if (n1 - n0 == n2 - n1) {
        ans = true;
    }
    
    //@ assert ans == (n1 - n0 == n2 - n1);
    
    return ans;
}
