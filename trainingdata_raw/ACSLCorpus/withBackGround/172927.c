#include <stdbool.h>

/*@
    predicate valid_vec(int *v) =
        \forall integer i; 0 <= i < 5 ==> 0 <= v[i] && v[i] <= 5 &&
        \forall integer i, j; 0 <= i < j < 5 ==> v[i] != v[j] &&
        (v[0] == v[1] || v[1] == v[2] || v[3] == v[4]);

    logic integer vec_at(int *v, integer i) = v[i];
*/

/*@
    requires \valid(v + (0..4));
    requires valid_vec(v);
    ensures 1 <= \result <= 5;
    ensures \result == v[0] || \result == v[1] || \result == v[2] || \result == v[3] || \result == v[4];
    ensures v[0] == v[1] || v[1] == v[2] || v[3] == v[4];
*/
int func(int *v)
{
    int p = 0;
    /*@
        loop invariant 0 <= p <= 5;
        loop invariant valid_vec(v);
        loop assigns p;
        loop variant 5 - p;
    */
    while (p < 5)
    {
        int i = p / 2;
        //@ assert 0 <= i <= 2;
        //@ assert (i + 1) % 5 >= 0 && (i + 1) % 5 < 5;
        if (v[i] == v[(i + 1) % 5])
        {
            //@ assert v[i] >= 1 && v[i] <= 5;
            return v[i];
        }
        p += 1;
    }
    return -1;
}
