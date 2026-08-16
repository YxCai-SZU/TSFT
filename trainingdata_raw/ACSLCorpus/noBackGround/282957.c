#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) < 0x80000000 && \valid((list1) + (0..(len)-1)));
    ensures \result == true ==> \exists integer i; 0 <= i < len && ((list1)[(i)]) == element;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> ((list1)[(i)]) != element;
*/
bool contains_element(int *list1, size_t len, int element)
{
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; (0) <= k < (i) ==> (((list1))[(k)]) != (element));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (list1[i] == element)
        {
            //@ assert (0 <= (i) < (len) && (((list1))[((i))]) == (element));
            return true;
        }
        i++;
    }
    //@ assert (\forall integer k; (0) <= k < (len) ==> (((list1))[(k)]) != (element));
    return false;
}

/*@
    requires 1 <= n <= 10;
    ensures \result == n + n * n + n * n * n;
*/
int func(int n)
{
    int result;
    int n_squared;
    int n_cubed;
    
    //@ assert 1 <= n && n <= 10;
    
    //@ assert 1 <= n * n && n * n <= 100;
    n_squared = n * n;
    
    //@ assert 1 <= n * n * n && n * n * n <= 1000;
    n_cubed = n * n * n;
    
    result = n;
    result += n_squared;
    result += n_cubed;
    
    //@ assert result == n + n * n + n * n * n;
    return result;
}
