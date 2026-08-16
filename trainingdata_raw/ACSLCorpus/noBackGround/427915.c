#include <stdbool.h>

/*@
    requires len > 0;
    requires \valid(arr + (0 .. len - 1));
    ensures ((\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] == (arr)[i + 1]) ==> \result == ((arr)[0])) ||
            (arr[0] != arr[1] ==> \result == ((arr)[1]));
*/
int find_element(int *arr, int len) {
    int result;
    int i;

    if (len == 1) {
        result = arr[0];
        return result;
    }

    if (arr[0] == arr[1]) {
        i = 1;
        /*@
            loop invariant 1 <= i <= len;
            loop invariant len > 0;
            loop invariant \forall integer j; 0 <= j < i ==> arr[j] == arr[j];
            loop assigns i;
            loop variant len - i;
        */
        while (i < len) {
            if (arr[i] != arr[0]) {
                result = arr[0];
                return result;
            }
            i++;
        }
        result = arr[0];
        return result;
    } else {
        if (len == 2) {
            result = arr[1];
            return result;
        } else {
            i = 2;
            /*@
                loop invariant 2 <= i <= len;
                loop invariant len > 0;
                loop invariant \forall integer j; 0 <= j < i ==> arr[j] == arr[j];
                loop assigns i;
                loop variant len - i;
            */
            while (i < len) {
                if (arr[i] != arr[1]) {
                    result = arr[1];
                    return result;
                }
                i++;
            }
            result = arr[1];
            return result;
        }
    }
}
