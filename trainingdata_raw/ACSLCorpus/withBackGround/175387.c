#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000;

    predicate condition_holds(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 
            (arr[i] % 2 != 0 || arr[i] % 6 == 0 || arr[i] % 10 == 0);
*/

/*@
    requires 1 <= n && n <= 100;
    requires \valid_read(input + (0 .. n-1));
    requires valid_range(input, n);
    assigns \nothing;
    ensures \result == true <==> condition_holds(input, n);
*/
bool func(size_t n, int *input) {
    bool flag = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true <==> 
            \forall integer j; 0 <= j < i ==> 
                (input[j] % 2 != 0 || input[j] % 6 == 0 || input[j] % 10 == 0);
        loop invariant valid_range(input, n);
        loop assigns flag, i;
        loop variant n - i;
    */
    while (i < n) {
        int value = input[i];
        //@ assert 1 <= value <= 1000;
        if (value % 2 == 0 && value % 6 != 0 && value % 10 != 0) {
            flag = false;
        }
        i++;
    }
    
    return flag;
}
