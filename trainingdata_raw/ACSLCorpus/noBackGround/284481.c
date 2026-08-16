#include <stdbool.h>

/*@
    requires \valid(arr + (0..2));
    requires ((3) == 3 &&
        (1 <= ((arr)[0]) <= 100) &&
        (1 <= ((arr)[1]) <= 100) &&
        (arr)[0] == (arr)[2]);
    ensures \result == arr[0] || \result == arr[1] || \result == arr[2];
    ensures 1 <= \result <= 100;
*/
int find_peak(int *arr) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= 3;
        loop invariant max == arr[0] || max == arr[1] || max == arr[2];
        loop invariant 1 <= max <= 100;
        loop invariant ((3) == 3 &&
        (1 <= ((arr)[0]) <= 100) &&
        (1 <= ((arr)[1]) <= 100) &&
        (arr)[0] == (arr)[2]);
        loop assigns max, i;
    */
    while (i < 3) {
        //@ assert ((3) == 3 &&         (1 <= ((arr)[0]) <= 100) &&         (1 <= ((arr)[1]) <= 100) &&         (arr)[0] == (arr)[2]);
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    
    //@ assert max == arr[0] || max == arr[1] || max == arr[2];
    return max;
}

int main() {
    return 0;
}
