#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((len) >= 1 &&
        \forall size_t i; 0 <= i < (len) ==> 1 <= (numbers)[i] && (numbers)[i] <= 100);
    ensures \result >= 0 && \result <= 99;
    assigns \nothing;
*/
int func(int *numbers, size_t len) {
    int min = 100;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant \forall size_t k; 0 <= k < index ==> min <= numbers[k];
        loop invariant 1 <= min <= 100;
        loop assigns min, index;
        loop variant len - index;
    */
    while (index < len) {
        int i = numbers[index];
        //@ assert 1 <= i <= 100;
        min = (i < min) ? i : min;
        //@ assert 1 <= min <= 100;
        index++;
    }
    
    int result = 0;
    index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant \forall size_t k; 0 <= k < index ==> result >= numbers[k] - min;
        loop invariant 0 <= result <= 99;
        loop invariant 1 <= min <= 100;
        loop assigns result, index;
        loop variant len - index;
    */
    while (index < len) {
        int i = numbers[index];
        //@ assert 1 <= i <= 100;
        int diff = i - min;
        //@ assert diff >= 0;
        result = (diff > result) ? diff : result;
        //@ assert result >= 0 && result <= 99;
        index++;
    }
    
    return result;
}
