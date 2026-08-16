#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 2 && n <= 50;
    requires \valid(arr + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> arr[i] >= 0 && arr[i] <= 100;
    ensures \result == true <==> 
            (\exists integer i; 0 <= i < n && arr[i] == 0) ||
            (\exists integer i; 0 <= i < n && arr[i] >= 5 && arr[i] <= 15);
    assigns \nothing;
*/
bool func(size_t n, int* arr) {
    size_t i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> 
                       !(arr[k] == 0 || (arr[k] >= 5 && arr[k] <= 15));
        loop invariant \forall integer j; 0 <= j < n ==> arr[j] >= 0 && arr[j] <= 100;
        loop invariant n >= 2 && n <= 50;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        int a = arr[i];
        //@ assert (0 <= (i) < (n) ==> (arr)[(i)] >= 0 && (arr)[(i)] <= 100);
        if (a == 0 || (a >= 5 && a <= 15)) {
            //@ assert (\exists integer i; 0 <= i < (n) && (arr)[i] == 0) || (\exists integer i; 0 <= i < (n) && (arr)[i] >= 5 && (arr)[i] <= 15);
            return true;
        }
        i++;
    }
    //@ assert \forall integer k; 0 <= k < n ==> !(arr[k] == 0 || (arr[k] >= 5 && arr[k] <= 15));
    return false;
}
