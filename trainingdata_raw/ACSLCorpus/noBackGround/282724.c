#include <stdbool.h>
#include <stddef.h>

/*@
    requires n >= 1 && n <= 100;
    requires \valid_read(numbers + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000);
    ensures \result == true <==> (\forall integer j; 0 <= j < ((n)) ==> 
            ((numbers)[j] % 2 != 0) || ((numbers)[j] % 6 == 0) || ((numbers)[j] % 10 == 0));
    assigns \nothing;
*/
bool func(size_t n, int *numbers) {
    bool flag = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true <==> (\forall integer j; 0 <= j < (i) ==> 
            ((numbers)[j] % 2 != 0) || ((numbers)[j] % 6 == 0) || ((numbers)[j] % 10 == 0));
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000);
        loop assigns i, flag;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        if (a % 2 == 0) {
            if (a % 6 != 0 && a % 10 != 0) {
                flag = false;
            }
        }
        i++;
    }
    return flag;
}
