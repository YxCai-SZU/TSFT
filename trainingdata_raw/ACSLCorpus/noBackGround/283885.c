#include <stdbool.h>

/*@
  requires \valid(numbers + (0..2));
  requires (1 <= (numbers[0]) && (numbers[0]) <= 100);
  requires (1 <= (numbers[1]) && (numbers[1]) <= 100);
  requires (1 <= (numbers[2]) && (numbers[2]) <= 100);
  ensures \result == true <==> ((numbers[0]) + (numbers[1]) == (numbers[2]) || (numbers[1]) + (numbers[2]) == (numbers[0]) || (numbers[0]) + (numbers[2]) == (numbers[1]));
  assigns \nothing;
*/
bool func(int numbers[3]) {
    int a, b, c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);

    if (a + b == c || b + c == a || a + c == b) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> ((a) + (b) == (c) || (b) + (c) == (a) || (a) + (c) == (b));
    return result;
}
