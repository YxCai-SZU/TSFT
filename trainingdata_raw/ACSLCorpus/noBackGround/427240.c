#include <stdbool.h>

/*@
  requires \valid_read(numbers + (0..2));
  requires numbers[0] >= 1 && numbers[0] <= 100;
  requires numbers[1] >= 1 && numbers[1] <= 100;
  requires numbers[2] >= 1 && numbers[2] <= 100;
  ensures \result == true <==> ((numbers[1]) - (numbers[0]) == (numbers[2]) - (numbers[1]));
*/
bool func(const int numbers[3])
{
    int a;
    int b;
    int c;
    int diff1;
    int diff2;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a == numbers[0];
    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 == b - a;
    if (diff1 == diff2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> ((b) - (a) == (c) - (b));
    return result;
}
