#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100);
    requires (1 <= (m) && (m) <= 100);
    requires (1 <= (x) && (x) <= (n) - 1);
    requires \valid(an + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> ((an[i]) >= 1 && (an[i]) <= (n) && (an[i]) != (x));
    requires \valid(am + (0 .. m-1));
    requires \forall integer i; 0 <= i < m ==> 
             ((am[i]) >= 1 && (am[i]) <= (n) && (am[i]) != (x) && (am[i]) != (an[0]));
    ensures 0 <= \result <= m;
*/
int func(int n, int m, int x, int *an, int *am) {
    int count1 = 0;
    int count2 = 0;
    int min_count = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= count1 <= (int)i;
        loop assigns i, count1;
        loop variant m - i;
    */
    while (i < (size_t)m) {
        int friend = am[i];
        //@ assert ((friend) >= 1 && (friend) <= (n) && (friend) != (x) && (friend) != (an[0]));
        if (friend < x) {
            count1++;
        }
        i++;
    }

    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count2 <= (int)i;
        loop assigns i, count2;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        int friend = an[i];
        //@ assert ((friend) >= 1 && (friend) <= (n) && (friend) != (x));
        if (friend > x) {
            count2++;
        }
        i++;
    }

    min_count = count1;
    if (count2 < min_count) {
        min_count = count2;
    }

    //@ assert 0 <= min_count <= m;
    return min_count;
}
