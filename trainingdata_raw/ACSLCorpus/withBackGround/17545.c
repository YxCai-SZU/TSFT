#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer x) = (x % 2) == 0; */

/*@ lemma count_bound: \forall integer n, count;
    count <= n && count >= 0 ==> count <= n; */

/*@ requires n >= 0;
    requires \valid_read(numbers + (0 .. n-1));
    ensures \result <= n;
    ensures \result >= 0;
    assigns \nothing; */
uint32_t count_even_numbers(uint32_t n, int32_t* numbers) {
    // Variable declarations at top of scope
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
                   (is_even(numbers[k]) ==> count <= i);
        loop assigns i, count;
        loop variant n - i; */
    while (i < n) {
        int32_t x = numbers[i];
        
        //@ assert x == numbers[i];
        
        if ((x & 1) == 0) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert count <= n;
    
    return count;
}
