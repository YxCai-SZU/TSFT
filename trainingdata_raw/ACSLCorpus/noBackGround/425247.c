#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= a <= 100 && 1 <= b <= 100;
    ensures \result >= 0 && (\result == a - 2*b || \result == 0);
*/
int func(int a, int b)
{
    int result;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    result = a - 2 * b;
    //@ assert result == a - 2*b;
    if (result < 0)
    {
        //@ assert result < 0;
        result = 0;
        //@ assert result == 0;
        return result;
    }
    else
    {
        //@ assert result >= 0;
        return result;
    }
}

typedef struct {
    bool is_some;
    size_t value;
} Option;

/*@ requires \valid(nums+(0..len-1));
    ensures \result.is_some == false ==> 
             (\forall integer i; 0 <= i < (len) ==> (nums)[i] >= 0);
    ensures \result.is_some == true ==> 
             (0 <= (\result.value) < (len) && (nums)[(\result.value)] < 0 && (\forall integer i; 0 <= i < ((\result.value)) ==> ((nums))[i] >= 0));
*/
Option func_list(int *nums, size_t len)
{
    size_t index = 0;
    //@ assert index == 0;
    /*@ loop invariant 0 <= index <= len;
        loop invariant (\forall integer i; 0 <= i < (index) ==> (nums)[i] >= 0);
        loop assigns index;
        loop variant len - index;
    */
    while (index < len)
    {
        //@ assert 0 <= index < len;
        if (nums[index] < 0)
        {
            //@ assert nums[index] < 0;
            //@ assert (\forall integer i; 0 <= i < (index) ==> (nums)[i] >= 0);
            Option ret = {true, index};
            //@ assert (0 <= (index) < (len) && (nums)[(index)] < 0 && (\forall integer i; 0 <= i < ((index)) ==> ((nums))[i] >= 0));
            return ret;
        }
        //@ assert nums[index] >= 0;
        //@ assert (\forall integer i; 0 <= i < (index+1) ==> (nums)[i] >= 0);
        index++;
    }
    //@ assert index == len;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (nums)[i] >= 0);
    Option ret = {false, 0};
    return ret;
}
