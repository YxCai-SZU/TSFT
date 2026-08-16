#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (N) && (N) <= 100);
    requires \valid(numbers + (0 .. N-1));
    requires (\forall integer i; 0 <= i < (N) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 1000));
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int func(size_t N, const long long *numbers) {
    int Alice = 0;
    size_t index = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant index <= i;
        loop invariant 0 <= Alice <= (int)i;
        loop invariant index <= N;
        loop assigns Alice, index, i;
    */
    while (i < N) {
        long long num = numbers[index];
        
        //@ assert (1 <= (num) && (num) <= 1000);
        
        if ((i % 2 == 0) && (num % 2 == 1)) {
            Alice += 1;
        }
        
        index += 1;
        i += 1;
        
        //@ assert 0 <= Alice <= (int)i;
    }
    
    //@ assert 0 <= Alice <= (int)N;
    return Alice;
}
