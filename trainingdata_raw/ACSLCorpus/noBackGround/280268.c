#include <stdbool.h>
/*@
    requires \valid_read(numbers + (0..2));
    requires numbers[0] >= 1 && numbers[0] <= 13;
    requires numbers[1] >= 1 && numbers[1] <= 13;
    requires numbers[2] >= 1 && numbers[2] <= 13;
    ensures \result == (numbers[2] == numbers[0] + numbers[1]);
*/
bool func(const long long* numbers) {
    long long a;
    long long b;
    long long c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert (1 <= (a) && (a) <= 13);
    //@ assert (1 <= (b) && (b) <= 13);
    //@ assert (1 <= (c) && (c) <= 13);
    //@ assert a + b <= 26;

    if (c == a + b) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
