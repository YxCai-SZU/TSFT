#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
    \valid((input_numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *input_numbers) {
    int answer = 0;
    size_t index = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
    (answer) >= 0 && (answer) <= (index));
        loop invariant ((n) >= 1 && (n) <= 100 &&
    \valid((input_numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= 100);
        loop invariant index <= n;
        loop assigns answer, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int number = input_numbers[index];
        
        //@ assert index >= 0 && index < n;
        //@ assert number >= 1 && number <= 100;
        
        if ((int)index + 1 >= number) {
            answer += 1;
        }
        index += 1;
        
        //@ assert index >= 0 && index <= n;
    }
    return answer;
}
