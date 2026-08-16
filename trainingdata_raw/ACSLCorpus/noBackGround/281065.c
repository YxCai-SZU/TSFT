#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*@
    requires (2 <= (n) && (n) <= 200000 &&
        \valid((input_numbers) + (0 .. (n)-2)) &&
        \forall integer j; 0 <= j < (n)-1 ==> 1 <= (input_numbers)[j] && (input_numbers)[j] < j+1);
    ensures \valid(\result + (0 .. n-1));
    ensures \forall integer i; 0 <= i < n ==> 0 <= \result[i];
    assigns \nothing;
*/
uint32_t* func(size_t n, uint32_t* input_numbers) {
    uint32_t* ans;
    size_t i;
    size_t index;
    uint32_t current_value;
    
    ans = (uint32_t*)malloc(n * sizeof(uint32_t));
    //@ assert ans != \null;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \valid(ans + (0 .. n-1));
        loop invariant \forall integer j; 0 <= j < i ==> ans[j] == 0;
        loop assigns i, ans[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        ans[i] = 0;
        i++;
    }
    //@ assert (\valid((ans) + (0 .. (n)-1)) &&         \forall integer j; 0 <= j < (n) ==> (ans)[j] == 0);
    
    index = 0;
    /*@
        loop invariant 0 <= index <= n-1;
        loop invariant \valid(ans + (0 .. n-1));
        loop invariant \forall integer j; 0 <= j < n ==> 0 <= ans[j] && ans[j] <= index;
        loop invariant \forall integer j; 0 <= j < index ==> ans[input_numbers[j] - 1] > 0;
        loop assigns index, ans[0 .. n-1];
        loop variant n-1 - index;
    */
    while (index < n-1) {
        //@ assert 0 <= input_numbers[index] - 1 < n;
        size_t idx = (size_t)(input_numbers[index] - 1);
        current_value = ans[idx];
        ans[idx] = current_value + 1;
        index++;
    }
    //@ assert \forall integer i; 0 <= i < n ==> 0 <= ans[i];
    
    return ans;
}
