#include <stdbool.h>

/*@ requires ((n) >= 1 && (n) <= 100 && (x) >= 1 && (x) <= 10000);
    requires n >= 1;
    requires \valid(l + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (l)[i] >= 1 && (l)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *l) {
    int d = 0;
    int count = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= d <= x + 100;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> (l)[i] >= 1 && (l)[i] <= 100);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (l)[i] >= 1 && (l)[i] <= 100);
        loop invariant ((n) >= 1 && (n) <= 100 && (x) >= 1 && (x) <= 10000);
        loop assigns d, count, index;
    */
    while (index < n && d <= x) {
        //@ assert 0 <= index < n;
        int current_l = l[index];
        d += current_l;
        count += 1;
        index += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n + 1;
    return count;
}
