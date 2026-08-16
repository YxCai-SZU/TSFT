#include <stdbool.h>

/*@
requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> (1 <= ((nums)[i]) && ((nums)[i]) <= 5));
requires (1 <= (input) && (input) <= 5);
ensures \result >= 0;
assigns \nothing;
*/
int func(int input, int nums[5]) {
    int answer;
    int index;
    int num;
    
    answer = 0;
    index = 0;
    
    /*@
    loop invariant 0 <= index <= 5;
    loop invariant answer >= 0;
    loop invariant answer <= index;
    loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> (1 <= ((nums)[i]) && ((nums)[i]) <= 5));
    loop invariant (1 <= (input) && (input) <= 5);
    loop assigns answer, index, num;
    loop variant 5 - index;
    */
    while (index < 5) {
        num = nums[index];
        
        //@ assert (1 <= (num) && (num) <= 5);
        
        if (num == input) {
            answer = answer + 1;
        }
        
        //@ assert answer >= 0;
        
        index = index + 1;
    }
    
    //@ assert answer >= 0;
    return answer;
}
