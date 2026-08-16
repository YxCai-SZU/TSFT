#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100) && (1 <= (x) && (x) <= 10000);
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 100));
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
 */
int func(int n, int x, int *numbers) {
    int sum = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= (size_t)n;
        loop invariant sum >= 0;
        loop invariant sum <= index * 100;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 100));
        loop invariant (1 <= (n) && (n) <= 100) && (1 <= (x) && (x) <= 10000);
        loop assigns sum, index;
     */
    while (index < (size_t)n) {
        //@ assert 0 <= index < (size_t)n;
        //@ assert (1 <= (numbers[index]) && (numbers[index]) <= 100);
        sum += numbers[index];
        index++;
    }
    
    int result = (sum >= x) ? n : n + 1;
    //@ assert result >= 0 && result <= n + 1;
    return result;
}

/*@ requires \true;
    ensures \true;
    assigns \nothing;
 */
int main() {
    int numbers[2] = {100, 100};
    int n = 2;
    int x = 150;
    
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (1 <= (x) && (x) <= 10000);
    //@ assert (\forall integer i; 0 <= i < (n) ==> (1 <= ((&numbers[0])[i]) && ((&numbers[0])[i]) <= 100));
    
    int result = func(n, x, &numbers[0]);
    //@ assert result >= 0 && result <= n + 1;
    
    return 0;
}
