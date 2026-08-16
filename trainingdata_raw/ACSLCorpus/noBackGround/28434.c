#include <stdbool.h>

/*@ requires \valid(arr+(0..2));
    requires (\forall integer i, j; 0 <= i < j < (3) ==> (arr)[i] != (arr)[j]);
    requires (\forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] <= 13);
    ensures \result == 1 ==> (((arr[1]) == (arr[0]) + (arr[2])) || ((arr[2]) == (arr[1]) + (arr[0])) || ((arr[0]) == (arr[1]) + (arr[2])));
    ensures \result == 0 ==> !(((arr[1]) == (arr[0]) + (arr[2])) || ((arr[2]) == (arr[1]) + (arr[0])) || ((arr[0]) == (arr[1]) + (arr[2])));
*/
int can_arrange_gte(int *arr) {
    //@ assert arr[0] >= 1 && arr[0] <= 13;
    //@ assert arr[1] >= 1 && arr[1] <= 13;
    //@ assert arr[2] >= 1 && arr[2] <= 13;
    
    //@ assert arr[0] != arr[1];
    //@ assert arr[0] != arr[2];
    //@ assert arr[1] != arr[2];
    
    if (arr[1] == arr[0] + arr[2] || 
        arr[2] == arr[1] + arr[0] || 
        arr[0] == arr[1] + arr[2]) {
        return 1;
    } else {
        return 0;
    }
}
