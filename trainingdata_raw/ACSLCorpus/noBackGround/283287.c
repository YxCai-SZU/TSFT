#include <stdbool.h>
/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    //@ assert ((r) * (r)) >= 1;
    return r * r;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (a > b);
    assigns \nothing;
*/
bool input_tuple(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    return a > b;
}

/*@
    requires ((len) >= 1 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
    ensures 1 <= \result && \result <= 100;
    assigns \nothing;
*/
int input_array(int *arr, int len)
{
    //@ assert ((len) >= 1 &&         \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
    //@ assert 1 <= arr[0] && arr[0] <= 100;
    return arr[0];
}
