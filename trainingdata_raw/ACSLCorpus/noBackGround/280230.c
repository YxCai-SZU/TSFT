#include <stdbool.h>

/*@
  requires \valid(numbers + (0..2));
  requires (-100 <= (numbers[0]) <= 100);
  requires (-100 <= (numbers[1]) <= 100);
  requires (-100 <= (numbers[2]) <= 100);
  ensures \result == (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool main_function(int numbers[3]) {
    // Variable declarations
    bool result;
    
    //@ assert (-100 <= (numbers[0]) <= 100);
    //@ assert (-100 <= (numbers[1]) <= 100);
    //@ assert (-100 <= (numbers[2]) <= 100);
    
    result = numbers[0] < numbers[1] && numbers[1] < numbers[2];
    return result;
}
