#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100000;
    requires \valid(input_numbers + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= input_numbers[i] <= 1000000000;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> (input_numbers)[i] % 2 == 0);
*/
bool func(size_t n, const int input_numbers[]) {
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant \forall integer i; 0 <= i < index ==> input_numbers[i] % 2 == 0;
        loop assigns index;
        loop variant n - index;
    */
    while (index < n) {
        int a = input_numbers[index];
        //@ assert a == input_numbers[index];
        if (a % 2 != 0) {
            //@ assert !(\forall integer i; 0 <= i < (n) ==> (input_numbers)[i] % 2 == 0);
            return false;
        }
        index++;
    }
    //@ assert (\forall integer i; 0 <= i < (n) ==> (input_numbers)[i] % 2 == 0);
    return true;
}
