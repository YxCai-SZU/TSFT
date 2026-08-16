#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(input + (0..n-1));
    requires \forall integer i; 0 <= i < n ==> ((input[i]) > 0 && (input[i]) <= 1000);
    ensures \result == true <==> 
            \forall integer i; 0 <= i < n ==> ((input[i]) % 2 != 0 || (input[i]) % 6 == 0 || (input[i]) % 10 == 0);
    assigns \nothing;
*/
bool func(size_t n, const unsigned int input[]) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> ((input[j]) % 2 != 0 || (input[j]) % 6 == 0 || (input[j]) % 10 == 0);
        loop invariant \forall integer k; 0 <= k < n ==> ((input[k]) > 0 && (input[k]) <= 1000);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int a = input[i];
        
        //@ assert ((a) > 0 && (a) <= 1000);
        
        if (a % 2 == 0 && a % 6 != 0 && a % 10 != 0) {
            //@ assert !((a) % 2 != 0 || (a) % 6 == 0 || (a) % 10 == 0);
            return false;
        }
        
        //@ assert ((a) % 2 != 0 || (a) % 6 == 0 || (a) % 10 == 0);
        i += 1;
    }
    
    //@ assert \forall integer i; 0 <= i < n ==> ((input[i]) % 2 != 0 || (input[i]) % 6 == 0 || (input[i]) % 10 == 0);
    return true;
}
