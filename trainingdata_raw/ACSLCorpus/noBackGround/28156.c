#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len >= 2;
    requires (\forall integer i, j;
            0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
    ensures \result == true;
    ensures (\forall integer i, j;
            0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
*/
bool calc_example_unique_elements(unsigned int *arr, size_t len)
{
    //@ assert len >= 2;
    //@ assert (\forall integer i, j;             0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
    
    return true;
}

int main(void)
{
    return 0;
}
