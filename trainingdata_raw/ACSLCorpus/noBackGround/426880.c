#include <stdbool.h>

/*@
    requires \valid(nums + (0..2));
    requires -100 <= nums[0] <= 100;
    requires -100 <= nums[1] <= 100;
    requires -100 <= nums[2] <= 100;
    ensures \result == (nums[0] < nums[1] && nums[1] < nums[2]);
*/
bool check_increasing(int nums[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = nums[0];
    b = nums[1];
    c = nums[2];

    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;
    //@ assert -100 <= c <= 100;

    result = (a < b) && (b < c);
    return result;
}
