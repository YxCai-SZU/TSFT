#include <stdbool.h>
/*@
    predicate valid_array(int *arr, integer n) =
        n >= 1 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000;

    predicate condition_holds(int *arr, integer i) =
        \forall integer j; 0 <= j < i ==> 
            (arr[j] % 2 == 0 ==> arr[j] % 3 == 0 || arr[j] % 5 == 0);

    predicate condition_fails(int *arr, integer i) =
        \exists integer j; 0 <= j < i && 
            arr[j] % 2 == 0 && !(arr[j] % 3 == 0 || arr[j] % 5 == 0);
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid(numbers + (0 .. n-1));
    requires valid_array(numbers, n);
    ensures \result == true <==> 
        \forall integer i; 0 <= i < n ==> 
            (numbers[i] % 2 == 0 ==> numbers[i] % 3 == 0 || numbers[i] % 5 == 0);
    assigns \nothing;
*/
bool func(int n, int *numbers) {
    bool flag = true;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true ==> condition_holds(numbers, i);
        loop invariant flag == false ==> condition_fails(numbers, i);
        loop assigns flag, i;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        if (a % 2 == 0) {
            if (a % 3 != 0 && a % 5 != 0) {
                flag = false;
            }
        }
        i++;
        //@ assert flag == true ==> condition_holds(numbers, i);
    }
    return flag;
}
