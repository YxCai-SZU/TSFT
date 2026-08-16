#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires (\forall integer i; 0 <= i < (len) ==> -0x80000000 < (arr)[i] < 0x80000000);
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> (number) < (arr)[i]);
    ensures \result == false <==> !(\forall integer i; 0 <= i < (len) ==> (number) < (arr)[i]);
*/
bool check_less(int *arr, size_t len, int number)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> number < arr[j];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (number >= arr[i])
        {
            //@ assert !(\forall integer i; 0 <= i < (len) ==> (number) < (arr)[i]);
            return false;
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (number) < (arr)[i]);
    return true;
}
