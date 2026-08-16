#include <stdint.h>

/*@
    requires ((len) > 0 && (len) < 0x80000000 &&
        \valid((arr) + (0 .. (len)-1)));
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer j; 0 <= j < len ==> arr[j] <= \result;
    assigns \nothing;
*/
int32_t find_maximum(int32_t *arr, int32_t len)
{
    int32_t max;
    int32_t i;
    
    //@ assert len > 0 && len < 0x80000000;
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == max;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max;
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (arr[i] > max)
        {
            max = arr[i];
        }
        //@ assert \exists integer k; 0 <= k < i+1 && arr[k] == max;
        //@ assert \forall integer j; 0 <= j < i+1 ==> arr[j] <= max;
        i = i + 1;
    }
    //@ assert \exists integer i; 0 <= i < len && arr[i] == max;
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] <= max;
    return max;
}

int main(void)
{
    return 0;
}
