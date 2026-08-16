#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (numbers)[i] != (numbers)[j]);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int *numbers, size_t n) {
    size_t len = n;
    unsigned int ok_cnt = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant ok_cnt >= 0;
        loop invariant ok_cnt <= i;
        loop invariant \forall integer k; 0 <= k < i ==> numbers[k] >= 1 && numbers[k] <= len;
        loop invariant \forall integer x, y; 0 <= x < y < i ==> numbers[x] != numbers[y];
        loop assigns i, ok_cnt;
        loop variant len - i;
    */
    while (i < len) {
        bool is_valid = true;
        size_t j = 0;
        
        /*@
            loop invariant 0 <= j <= i;
            loop invariant is_valid == \true || is_valid == \false;
            loop invariant j == 0 ==> is_valid == \true;
            loop invariant j > 0 ==> (\forall integer k; 0 <= k < j ==> numbers[i] > numbers[k]) ==> is_valid == \true;
            loop invariant j > 0 ==> !(\forall integer k; 0 <= k < j ==> numbers[i] > numbers[k]) ==> is_valid == \false;
            loop assigns j, is_valid;
            loop variant i - j;
        */
        while (j < i) {
            //@ assert 0 <= j && j < i && i < len;
            if (!(numbers[i] > numbers[j])) {
                is_valid = false;
                break;
            }
            j++;
        }
        
        if (is_valid) {
            //@ assert ok_cnt + 1 <= i + 1;
            ok_cnt++;
        }
        i++;
    }
    //@ assert ok_cnt <= len;
    return (int)ok_cnt;
}
