#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n <= 100;
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
    ensures \result == true <==> 
            (\forall integer i; 0 <= i < n ==> 
                (numbers[i] % 2 != 0) || (numbers[i] % 6 == 0) || (numbers[i] % 10 == 0));
    assigns \nothing;
*/
bool func(size_t n, const int *numbers) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (\forall integer j; 0 <= j < (i) ==> 
            ((numbers)[j] % 2 != 0) || ((numbers)[j] % 6 == 0) || ((numbers)[j] % 10 == 0));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        
        //@ assert 1 <= a <= 1000;
        
        if (a % 2 == 0 && a % 6 != 0 && a % 10 != 0) {
            //@ assert !((a % 2 != 0) || (a % 6 == 0) || (a % 10 == 0));
            return false;
        }
        
        //@ assert (a % 2 != 0) || (a % 6 == 0) || (a % 10 == 0);
        i++;
    }
    
    //@ assert (\forall integer j; 0 <= j < ((n)) ==>              ((numbers)[j] % 2 != 0) || ((numbers)[j] % 6 == 0) || ((numbers)[j] % 10 == 0));
    return true;
}
