#include <stdbool.h>

/*@ requires \valid(a+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> (0 <= (a)[i] && (a)[i] <= 123));
    requires 0 <= k <= 123;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < (5) ==>
          ((a)[j] - (a)[i] <= (k) || (a)[i] - (a)[j] <= (k)));
    assigns \nothing;
 */
bool func(int a[5], int k)
{
    int i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < (5) ==> (0 <= (a)[i] && (a)[i] <= 123));
        loop invariant 0 <= k <= 123;
        loop invariant \forall integer x, y; 0 <= x < y < i ==> (a[y] - a[x] <= k || a[x] - a[y] <= k);
        loop assigns i;
        loop variant 5 - i;
     */
    while (i < 5)
    {
        int b[5];
        int index = 0;
        /*@ loop invariant 0 <= index <= 5;
            loop invariant \forall integer idx; 0 <= idx < index ==> b[idx] == (idx == i ? 0 : a[idx]);
            loop invariant (\forall integer i; 0 <= i < (5) ==> (0 <= (a)[i] && (a)[i] <= 123));
            loop invariant 0 <= k <= 123;
            loop invariant \forall integer x, y; 0 <= x < y < i ==> (a[y] - a[x] <= k || a[x] - a[y] <= k);
            loop assigns index, b[0..4];
            loop variant 5 - index;
         */
        while (index < 5)
        {
            b[index] = (index == i) ? 0 : a[index];
            //@ assert b[index] == (index == i ? 0 : a[index]);
            int diff = (a[i] > b[index]) ? (a[i] - b[index]) : (b[index] - a[i]);
            //@ assert diff == (a[i] > b[index] ? a[i] - b[index] : b[index] - a[i]);
            if (diff > k)
            {
                //@ assert diff > k;
            }
            index++;
        }
        i++;
    }
    //@ assert (\forall integer i, j; 0 <= i < j < (5) ==>           ((a)[j] - (a)[i] <= (k) || (a)[i] - (a)[j] <= (k)));
    return true;
}
