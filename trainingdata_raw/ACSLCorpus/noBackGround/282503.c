#include <stdbool.h>

/*@
  requires 1 <= v[0] && v[0] <= 100 && 
           1 <= v[1] && v[1] <= 100 && 
           1 <= v[2] && v[2] <= 100;
  ensures \result <==> ((v[0]) + (v[1]) == (v[2]) || (v[0]) + (v[2]) == (v[1]) || (v[1]) + (v[2]) == (v[0]));
*/
bool can_distribute_evenly(int v[3])
{
    int a = v[0];
    int b = v[1];
    int c = v[2];
    int min1;
    int mid;
    int max;

    //@ assert 1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= c && c <= 100;

    if (a <= b && a <= c) {
        if (b <= c) {
            min1 = a;
            mid = b;
            max = c;
        } else {
            min1 = a;
            mid = c;
            max = b;
        }
    } else if (b <= a && b <= c) {
        if (a <= c) {
            min1 = b;
            mid = a;
            max = c;
        } else {
            min1 = b;
            mid = c;
            max = a;
        }
    } else {
        if (a <= b) {
            min1 = c;
            mid = a;
            max = b;
        } else {
            min1 = c;
            mid = b;
            max = a;
        }
    }

    //@ assert min1 <= mid && mid <= max;
    //@ assert ((min1) + (mid) == (max) || (min1) + (max) == (mid) || (mid) + (max) == (min1)) ==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    return min1 + mid == max;
}
