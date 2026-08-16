#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0..2));
    requires (1 <= (numbers[0]) <= 100) && (1 <= (numbers[1]) <= 100) && (1 <= (numbers[2]) <= 100);
    ensures \result == ((((numbers[0]) + (numbers[1]) == (numbers[2])) ? 1 : (((numbers[1]) + (numbers[2]) == (numbers[0])) ? 1 : (((numbers[2]) + (numbers[0]) == (numbers[1])) ? 1 : 0))) == 1);
*/
bool func(const long long* numbers)
{
    long long a;
    long long b;
    long long c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100) && (1 <= ((c)) <= 100));

    result = (a + b == c) || (b + c == a) || (c + a == b);

    //@ assert result == ((((a) + (b) == (c)) ? 1 : (((b) + (c) == (a)) ? 1 : (((c) + (a) == (b)) ? 1 : 0))) == 1);
    return result;
}
