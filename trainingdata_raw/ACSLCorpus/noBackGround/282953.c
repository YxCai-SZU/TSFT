#include <stdbool.h>
/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((3) == 3 &&
        1 <= (arr)[0] <= 20 &&
        1 <= (arr)[1] <= 20 &&
        1 <= (arr)[2] <= 20);
    ensures \result == ((arr[0]) - ((arr[1]) - (arr[2])));
*/
int func(const int *arr) {
    int water_height;
    //@ assert ((3) == 3 &&         1 <= (arr)[0] <= 20 &&         1 <= (arr)[1] <= 20 &&         1 <= (arr)[2] <= 20);
    water_height = arr[0] - (arr[1] - arr[2]);
    //@ assert water_height == ((arr[0]) - ((arr[1]) - (arr[2])));
    return water_height;
}
