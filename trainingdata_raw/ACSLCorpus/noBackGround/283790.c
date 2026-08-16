#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires ((3) >= 3 &&
        1 <= (numbers)[0] && (numbers)[0] <= 13 &&
        1 <= (numbers)[1] && (numbers)[1] <= 13 &&
        1 <= (numbers)[2] && (numbers)[2] <= 13);
    ensures \result == (numbers[2] == numbers[0] || 
                       numbers[2] == numbers[1] || 
                       numbers[2] == numbers[0] + numbers[1]);
*/
bool func(int *numbers) {
    int a;
    int b;
    int c;
    int sum;
    bool ans;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    sum = a + b;
    ans = false;

    if (sum == c) {
        ans = true;
    } else if (a == c) {
        ans = true;
    } else if (b == c) {
        ans = true;
    }

    //@ assert ans == (c == a || c == b || c == a + b);
    return ans;
}
