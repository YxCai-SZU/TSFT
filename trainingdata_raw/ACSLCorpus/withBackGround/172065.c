#include <stdbool.h>

/*@
    predicate is_valid_range(int *arr, integer n) =
        n >= 1 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000;

    predicate condition_holds(int *arr, integer n, integer i) =
        \forall integer j; 0 <= j < i && arr[j] % 2 == 0 ==> 
        (arr[j] % 3 == 0 || arr[j] % 5 == 0);

    lemma final_condition:
        \forall int *arr, integer n, bool flag;
        is_valid_range(arr, n) && 
        (flag == true <==> condition_holds(arr, n, n)) ==>
        (flag == true <==> 
            \forall integer i; 0 <= i < n && arr[i] % 2 == 0 ==> 
            (arr[i] % 3 == 0 || arr[i] % 5 == 0));
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid(input_vec + (0 .. n-1));
    requires is_valid_range(input_vec, n);
    ensures \result == true <==> 
            \forall integer i; 0 <= i < n && input_vec[i] % 2 == 0 ==> 
            (input_vec[i] % 3 == 0 || input_vec[i] % 5 == 0);
*/
bool func(int n, int *input_vec) {
    bool flag = true;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant is_valid_range(input_vec, n);
        loop invariant flag == true <==> condition_holds(input_vec, n, i);
        loop assigns i, flag;
        loop variant n - i;
    */
    while (i < n) {
        int value = input_vec[i];
        
        if (value % 2 != 0) {
            i++;
            continue;
        }
        
        if (value % 3 == 0 || value % 5 == 0) {
            i++;
            continue;
        }
        
        flag = false;
        break;
    }
    
    //@ assert flag == true <==> condition_holds(input_vec, n, n);
    return flag;
}
