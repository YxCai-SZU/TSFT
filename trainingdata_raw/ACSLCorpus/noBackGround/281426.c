#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (numbers)[i] > 0);
    assigns \nothing;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < (n) ==> (numbers)[i] % 2 == 0);
    ensures \result != -1 ==> (\exists integer i; 0 <= i < (n) && (numbers)[i] == (\result) && (\result) % 2 != 0);
*/
int func(int n, int *numbers) {
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant \forall integer i; 0 <= i < index ==> numbers[i] % 2 == 0;
        loop assigns index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (numbers[index] % 2 != 0) {
            //@ assert numbers[index] % 2 != 0;
            //@ assert (\exists integer i; 0 <= i < (n) && (numbers)[i] == (numbers[index]) && (numbers[index]) % 2 != 0);
            return numbers[index];
        }
        //@ assert numbers[index] % 2 == 0;
        index = index + 1;
    }
    //@ assert index == n;
    //@ assert (\forall integer i; 0 <= i < (n) ==> (numbers)[i] % 2 == 0);
    return -1;
}
