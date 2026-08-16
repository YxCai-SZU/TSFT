#include <stdbool.h>

/*@
    requires \valid(arr + (0..2));
    requires ((arr[0]) != (arr[1]) && (arr[1]) != (arr[2]) && (arr[0]) != (arr[2]));

    assigns \nothing;

    ensures ((arr[0]) != (arr[1]) && (arr[1]) != (arr[2]) && (arr[0]) != (arr[2]));
    ensures (((arr[0]) < (arr[1]) && (arr[1]) < (arr[2]) && (\result) == 1) ? 1 :
        ((arr[0]) > (arr[1]) && (arr[1]) > (arr[2]) && (\result) == -1) ? 1 :
        ((((arr[0]) < (arr[1]) && (arr[1]) > (arr[2])) || ((arr[0]) > (arr[1]) && (arr[1]) < (arr[2]))) && (\result) == 0) ? 1 : 0) == 1;
*/
int can_arrange_gte(int arr[3]) {
    int ret;

    //@ assert ((arr[0]) != (arr[1]) && (arr[1]) != (arr[2]) && (arr[0]) != (arr[2]));

    if (arr[0] < arr[1] && arr[1] < arr[2]) {
        //@ assert arr[0] < arr[1] && arr[1] < arr[2];
        ret = 1;
    } else if (arr[0] > arr[1] && arr[1] > arr[2]) {
        //@ assert arr[0] > arr[1] && arr[1] > arr[2];
        ret = -1;
    } else {
        //@ assert (arr[0] < arr[1] && arr[1] > arr[2]) || (arr[0] > arr[1] && arr[1] < arr[2]);
        ret = 0;
    }

    //@ assert ((arr[0]) != (arr[1]) && (arr[1]) != (arr[2]) && (arr[0]) != (arr[2]));
    //@ assert (((arr[0]) < (arr[1]) && (arr[1]) < (arr[2]) && (ret) == 1) ? 1 :         ((arr[0]) > (arr[1]) && (arr[1]) > (arr[2]) && (ret) == -1) ? 1 :         ((((arr[0]) < (arr[1]) && (arr[1]) > (arr[2])) || ((arr[0]) > (arr[1]) && (arr[1]) < (arr[2]))) && (ret) == 0) ? 1 : 0) == 1;
    return ret;
}
