#include <stdbool.h>

/*@ predicate is_triangle(integer a, integer b, integer c) =
      a + b > c &&
      b + c > a &&
      c + a > b;
*/

/*@
  requires \valid_read(numbers + (0..2));
  requires numbers[0] >= 1 && numbers[0] <= 13;
  requires numbers[1] >= 1 && numbers[1] <= 13;
  requires numbers[2] >= 1 && numbers[2] <= 13;
  ensures \result == 1 <==> is_triangle(numbers[0], numbers[1], numbers[2]);
*/
bool func(unsigned int* numbers) {
    bool result = false;
    //@ assert numbers[0] >= 1 && numbers[0] <= 13;
    
    if (numbers[1] + numbers[2] > numbers[0] &&
        numbers[2] + numbers[0] > numbers[1] &&
        numbers[0] + numbers[1] > numbers[2]) {
        result = true;
    }
    
    //@ assert result == 1 <==> is_triangle(numbers[0], numbers[1], numbers[2]);
    return result;
}
