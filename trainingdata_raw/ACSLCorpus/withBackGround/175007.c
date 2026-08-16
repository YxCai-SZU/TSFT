#include <stdbool.h>

/*@ predicate is_arithmetic_progression(integer a, integer b, integer c) =
      b - a == c - b;
*/

/*@
  requires \valid_read(numbers + (0..2));
  requires numbers[0] >= 1 && numbers[0] <= 1000000000;
  requires numbers[1] >= 1 && numbers[1] <= 1000000000;
  requires numbers[2] >= 1 && numbers[2] <= 1000000000;
  ensures \result == true <==> is_arithmetic_progression(numbers[0], numbers[1], numbers[2]);
*/
bool func(const long long* numbers) {
    long long a;
    long long b;
    long long c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    if (b - a == c - b) {
        //@ assert is_arithmetic_progression(a, b, c);
        result = true;
    } else {
        //@ assert !is_arithmetic_progression(a, b, c);
        result = false;
    }

    return result;
}
