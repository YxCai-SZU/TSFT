#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 && (x) >= 1 && (x) <= 10000);
    requires (\valid_read((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int x, const unsigned int *numbers) {
    unsigned int sum = 0;
    unsigned int count = 0;
    unsigned int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= sum <= x + 100*i;
        loop invariant 0 <= count <= i;
        loop invariant ((n) >= 1 && (n) <= 100 && (x) >= 1 && (x) <= 10000);
        loop invariant (\valid_read(((unsigned int*)numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> ((unsigned int*)numbers)[i] >= 1 && ((unsigned int*)numbers)[i] <= 100);
        loop assigns sum, count, i;
        loop variant n - i;
    */
    while (i < n && sum <= x) {
        //@ assert 0 <= i < n;
        //@ assert numbers[i] >= 1 && numbers[i] <= 100;
        sum += numbers[i];
        count += 1;
        i += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n + 1;
    return count;
}
