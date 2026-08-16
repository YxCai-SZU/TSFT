#include <stdbool.h>
/*@
    requires 2 <= n;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) >= 2 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int *numbers) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant a >= 0 && b >= 0 && c >= 0 && d >= 0;
        loop invariant a <= index && b <= index && c <= index && d <= index;
        loop invariant ((n) >= 2 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
        loop assigns index, a, b, c, d;
        loop variant n - index;
    */
    while (index < n) {
        int number = numbers[index];
        //@ assert 1 <= number <= 100;
        
        if (number == 1) {
            a += 1;
        } else if (number == 2) {
            b += 1;
        } else if (number == 3) {
            c += 1;
        } else if (number == 4) {
            d += 1;
        }
        index += 1;
    }

    int max1 = (a > b) ? a : b;
    int max2 = (c > d) ? c : d;
    int max = (max1 > max2) ? max1 : max2;
    
    //@ assert max >= 0;
    return max;
}
