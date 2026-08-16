#include <stdbool.h>

/*@
  requires \valid_read(numbers + (0..2));
  requires (1 <= (numbers[0]) && (numbers[0]) <= 100 &&
      1 <= (numbers[1]) && (numbers[1]) <= 100 &&
      1 <= (numbers[2]) && (numbers[2]) <= 200);
  assigns \nothing;
  ensures \result == 1 <==> ((numbers[0]) <= (numbers[2]) && ((numbers[2]) - (numbers[0]) <= (numbers[1])));
*/
bool func(const int numbers[3]) {
    bool result;
    
    //@ assert (1 <= (numbers[0]) && (numbers[0]) <= 100 &&       1 <= (numbers[1]) && (numbers[1]) <= 100 &&       1 <= (numbers[2]) && (numbers[2]) <= 200);
    
    if (numbers[0] <= numbers[2] && (numbers[2] - numbers[0] <= numbers[1])) {
        //@ assert ((numbers[0]) <= (numbers[2]) && ((numbers[2]) - (numbers[0]) <= (numbers[1])));
        result = true;
    } else {
        //@ assert !((numbers[0]) <= (numbers[2]) && ((numbers[2]) - (numbers[0]) <= (numbers[1])));
        result = false;
    }
    
    return result;
}
