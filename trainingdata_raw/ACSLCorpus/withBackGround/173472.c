#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = -100 <= x && x <= 100; */

/*@
  requires \valid(numbers + (0..2));
  requires is_valid_range(numbers[0]);
  requires is_valid_range(numbers[1]);
  requires is_valid_range(numbers[2]);
  assigns \nothing;
  ensures \result == (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool func(int numbers[3]) {
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

    result = a < b && b < c;
    return result;
}
