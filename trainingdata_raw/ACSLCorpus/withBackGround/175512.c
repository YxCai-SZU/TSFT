#include <stdbool.h>

/*@
    predicate is_increasing(integer a, integer b, integer c, integer d) =
        a < b && b < c && c < d;
*/

/*@
    requires \valid_read(numbers + (0..3));
    requires numbers[0] < 0x80000000;
    requires numbers[1] < 0x80000000;
    requires numbers[2] < 0x80000000;
    requires numbers[3] < 0x80000000;
    ensures \result >= 0;
    ensures \result <= 1;
    ensures \result == 1 <==> is_increasing(numbers[0], numbers[1], numbers[2], numbers[3]);
*/
int count_increasing_quadruplets(const int* numbers) {
    int a;
    int b;
    int c;
    int d;
    int count;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    d = numbers[3];
    count = 0;

    if (a < b && b < c && c < d) {
        count = count + 1;
    }

    //@ assert count == 1 <==> is_increasing(a, b, c, d);

    return count;
}
