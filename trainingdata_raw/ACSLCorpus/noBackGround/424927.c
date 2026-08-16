#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) <= 100000);
    requires (\valid((input_numbers) + (0 .. (n)-1)) && 
      \forall integer i; 0 <= i < (n) ==> (1 <= ((input_numbers)[i]) <= 1000000000));
    ensures \result >= -1;
    ensures \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, size_t *input_numbers) {
    size_t before = 0;
    int answer = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= answer <= (int)i;
        loop invariant 0 <= before <= 1000000000;
        loop assigns i, before, answer;
        loop variant n - i;
    */
    while (i < n) {
        size_t current = input_numbers[i];
        
        //@ assert (1 <= (current) <= 1000000000);
        
        if (before >= current) {
            answer += 1;
            //@ assert answer >= 0;
        } else {
            before = current;
            //@ assert before >= 0;
        }
        
        i += 1;
        //@ assert i <= n;
    }
    
    //@ assert answer >= 0;
    //@ assert answer <= (int)n;
    
    if (answer == 0) {
        return -1;
    } else {
        return answer;
    }
}
