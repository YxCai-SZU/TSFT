#include <stdbool.h>

/*@
  requires \valid_read(input + (0..2));
  requires input[0] >= -100 && input[0] <= 100;
  requires input[1] >= -100 && input[1] <= 100;
  requires input[2] >= -100 && input[2] <= 100;
  requires input[0] != input[1];
  ensures \result == 1 <==> (((input[0]) < (input[1]) && (input[0]) < (input[2]) && (input[2]) < (input[1])) || ((input[0]) > (input[1]) && (input[0]) > (input[2]) && (input[2]) > (input[1])));
*/
bool func(const long long* input)
{
    long long a;
    long long b;
    long long c;
    long long min;
    long long max;
    bool result;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert a != b;

    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }

    //@ assert min == (a < b ? a : b);
    //@ assert max == (a < b ? b : a);

    if (min < c && c < max) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == 1 <==> (((a) < (b) && (a) < (c) && (c) < (b)) || ((a) > (b) && (a) > (c) && (c) > (b)));
    return result;
}
