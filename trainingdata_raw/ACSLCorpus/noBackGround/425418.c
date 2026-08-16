#include <stdbool.h>

/*@ requires (3 <= (n) && (n) <= 100);
    requires (1 <= (a) && (a) < (b) && (b) < 20);
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int a, int b, int *p) {
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    int min_count = 0;
    int i = 0;

    // First loop: count elements <= a
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n ==> 1 <= p[i] && p[i] <= 20;
        if (p[i] <= a) {
            count++;
        }
        i++;
    }

    // Second loop: count elements > a and <= b
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant count1 >= 0;
        loop invariant count1 <= i;
        loop assigns i, count1;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n ==> 1 <= p[i] && p[i] <= 20;
        if (p[i] <= b && p[i] > a) {
            count1++;
        }
        i++;
    }

    // Third loop: count elements > b
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant count2 >= 0;
        loop invariant count2 <= i;
        loop assigns i, count2;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n ==> 1 <= p[i] && p[i] <= 20;
        if (p[i] > b) {
            count2++;
        }
        i++;
    }

    // Calculate minimum count
    if (count < count1) {
        if (count < count2) {
            min_count = count;
        } else {
            min_count = count2;
        }
    } else if (count1 < count2) {
        min_count = count1;
    } else {
        min_count = count2;
    }

    // Final verification
    //@ assert min_count >= 0;
    //@ assert min_count <= n;
    return min_count;
}
