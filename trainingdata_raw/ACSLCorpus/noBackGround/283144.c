#include <stdbool.h>
#include <stdint.h>

/*@
    requires (2 <= (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= 1000000000 &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(uint32_t n, int64_t *p) {
    int64_t answer = 0;
    int64_t max = p[0];
    uint32_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (answer) >= 0 &&
        (answer) <= (i) &&
        (2 <= ((n)) <= 200000 &&
        \valid(((p)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= 1000000000 &&
        \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]));
        loop assigns i, answer, max;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) <= (n) &&         (answer) >= 0 &&         (answer) <= (i) &&         (2 <= ((n)) <= 200000 &&         \valid(((p)) + (0 .. ((n))-1)) &&         \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= 1000000000 &&         \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]));
        
        if (p[i] <= max) {
            answer += 1;
            max = p[i];
        } else {
            max = p[i];
        }
        i += 1;
        
        //@ assert (0 <= (i) <= (n) &&         (answer) >= 0 &&         (answer) <= (i) &&         (2 <= ((n)) <= 200000 &&         \valid(((p)) + (0 .. ((n))-1)) &&         \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= 1000000000 &&         \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]));
    }
    
    return answer;
}
