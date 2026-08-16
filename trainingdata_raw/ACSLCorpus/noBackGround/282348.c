#include <stdbool.h>

/*@
    requires (\valid((v) + (0 .. 4)));
    requires (\forall integer i; 0 <= i < 5 ==> 0 <= *((v) + i) <= 123);
    requires (0 <= (k) <= 123);
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < 5 ==>
            (*((v) + j) - *((v) + i) <= (k) || *((v) + i) - *((v) + j) <= (k)));
*/
bool func(int *v, int k) {
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    int diff = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\valid((v) + (0 .. 4)));
        loop invariant (\forall integer i; 0 <= i < 5 ==> 0 <= *((v) + i) <= 123);
        loop invariant (0 <= (k) <= 123);
        loop invariant \forall integer x, y; 0 <= x < y < i ==>
            (*(v + y) - *(v + x) <= k || *(v + x) - *(v + y) <= k);
        loop assigns i, j, a, b, diff;
        loop variant 5 - i;
    */
    while (i < 5) {
        a = *(v + i);
        j = 0;

        /*@
            loop invariant 0 <= j <= 5;
            loop invariant (\valid((v) + (0 .. 4)));
            loop invariant (\forall integer i; 0 <= i < 5 ==> 0 <= *((v) + i) <= 123);
            loop invariant (0 <= (k) <= 123);
            loop invariant a == *(v + i);
            loop invariant \forall integer x, y; 0 <= x < i && 0 <= y < j ==>
                (*(v + y) - *(v + x) <= k || *(v + x) - *(v + y) <= k);
            loop assigns j, b, diff;
            loop variant 5 - j;
        */
        while (j < 5) {
            b = *(v + j);
            diff = (a > b) ? (a - b) : (b - a);
            //@ assert diff >= 0;
            j += 1;
        }
        i += 1;
    }
    //@ assert (\forall integer i, j; 0 <= i < j < 5 ==>             (*((v) + j) - *((v) + i) <= (k) || *((v) + i) - *((v) + j) <= (k)));
    return true;
}
