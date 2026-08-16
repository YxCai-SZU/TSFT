#include <stdbool.h>

/*@
    requires \valid(arr + (0..2));
    requires arr[0] > -2147483648;
    requires arr[1] > -2147483648;
    requires arr[2] > -2147483648;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> ((arr[0]) < (arr[1]) && (arr[1]) < (arr[2]));
    ensures \result == -1 ==> ((arr[0]) >= (arr[1]) || (arr[1]) >= (arr[2]));
*/
int can_arrange_gte(int arr[3])
{
    int ret;
    //@ assert arr[0] > -2147483648;
    //@ assert arr[1] > -2147483648;
    //@ assert arr[2] > -2147483648;
    
    if (arr[0] < arr[1] && arr[1] < arr[2]) {
        //@ assert ((arr[0]) < (arr[1]) && (arr[1]) < (arr[2]));
        ret = 1;
    } else {
        //@ assert ((arr[0]) >= (arr[1]) || (arr[1]) >= (arr[2]));
        ret = -1;
    }
    return ret;
}
