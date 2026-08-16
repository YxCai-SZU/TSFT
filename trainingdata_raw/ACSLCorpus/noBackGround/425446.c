#include <stdbool.h>
#include <stdint.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(numbers + (0..n-1));
    requires \forall integer i; 0 <= i < n ==> ((numbers[i]) > 0 && (numbers[i]) <= 1000);
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (((numbers[i]) % 2 == 0 && (numbers[i]) % 3 == 0 && (numbers[i]) % 5 == 0) ==> \result > 0);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t numbers[]) {
    uint32_t count;
    uint32_t i;
    
    count = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (((numbers[j]) % 2 == 0 && (numbers[j]) % 3 == 0 && (numbers[j]) % 5 == 0) ==> count > 0);
        loop invariant \forall integer j; 0 <= j < n ==> ((numbers[j]) > 0 && (numbers[j]) <= 1000);
        loop invariant n > 0 && n <= 100;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        uint32_t a;
        a = numbers[i];
        
        if (a % 2 == 0 && a % 3 == 0 && a % 5 == 0) {
            //@ assert ((a) % 2 == 0 && (a) % 3 == 0 && (a) % 5 == 0);
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    return count;
}
