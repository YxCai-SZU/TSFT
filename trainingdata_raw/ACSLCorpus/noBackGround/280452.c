#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0..2));
    ensures \result == (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool func(const int* numbers)
{
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a == numbers[0] && b == numbers[1] && c == numbers[2];
    
    result = (a < b) && (b < c);
    return result;
}
