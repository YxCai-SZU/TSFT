#include <stdbool.h>

/*@ predicate is_sorted(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@
  requires \valid_read(numbers + (0..2));
  assigns \nothing;
  ensures \result == (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool is_range_sorted(const int numbers[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a == numbers[0];
    //@ assert b == numbers[1];
    //@ assert c == numbers[2];

    result = (a < b) && (b < c);
    return result;
}
