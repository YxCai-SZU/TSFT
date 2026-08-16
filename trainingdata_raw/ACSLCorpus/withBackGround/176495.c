#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x && x <= 100; */

/*@
  requires \valid(numbers + (0..2));
  requires is_valid_range(numbers[0]);
  requires is_valid_range(numbers[1]);
  requires is_valid_range(numbers[2]);
  ensures \result == true <==> (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool func(int numbers[3]) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert is_valid_range(numbers[0]);
    //@ assert is_valid_range(numbers[1]);
    //@ assert is_valid_range(numbers[2]);
    
    if (numbers[0] < numbers[1] && numbers[1] < numbers[2]) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
