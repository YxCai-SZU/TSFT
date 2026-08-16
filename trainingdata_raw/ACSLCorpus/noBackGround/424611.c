#include <stdbool.h>

/*@
    requires
        \valid(arr + (0 .. 2)) &&
        (\forall integer i, j; 0 <= i < j < (3) ==> (arr)[i] != (arr)[j]) &&
        (\forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 3);
    ensures
        0 <= \result <= 6;
*/
int can_arrange_gte(int arr[3])
{
    int count = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant 0 <= count <= 6;
        loop invariant count <= (int)i;
        loop assigns count, i;
        loop variant 3 - i;
    @*/
    while (i < 3) {
        int n = arr[i];
        //@ assert 1 <= n <= 3;
        if (n == count + 1) {
            count = n;
        }
        i++;
    }
    //@ assert 0 <= count <= 6;
    return count;
}
