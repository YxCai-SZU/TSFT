#include <stdbool.h>

/*@
    requires \valid(numbers + (0..2));
    requires -100 <= numbers[0] <= 100;
    requires -100 <= numbers[1] <= 100;
    requires -100 <= numbers[2] <= 100;
    assigns \nothing;
    ensures \result == (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool func(const long long* numbers) {
    long long a;
    long long b;
    long long c;
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
