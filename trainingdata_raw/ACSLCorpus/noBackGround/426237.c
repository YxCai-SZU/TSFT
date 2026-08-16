#include <stdbool.h>

/*@ requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int k, int *h) {
    int num = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= num <= index;
        loop invariant \forall integer j; 0 <= j < index ==> (k <= h[j] ==> num >= 0 && num <= index);
        loop assigns num, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (k <= h[index]) {
            num += 1;
            //@ assert num >= 0 && num <= index+1;
        }
        index += 1;
    }
    return num;
}
