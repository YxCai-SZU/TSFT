#include <stdbool.h>
#include <stdint.h>

/*@
    requires N > 0;
    requires \valid_read(numbers + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> numbers[i] > 0;
    assigns \nothing;
    ensures 0 <= \result <= N;
    ensures (\forall integer i; 0 <= i < (N) ==>
            ((numbers)[i] % 2 == 0 ==>
                (numbers)[i] % 3 == 0 ||
                (numbers)[i] % 5 == 0 ||
                (\result) > 0));
*/
uint32_t func(uint32_t N, uint32_t *numbers)
{
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==>
            (numbers[j] % 2 == 0 ==>
                numbers[j] % 3 == 0 ||
                numbers[j] % 5 == 0 ||
                count > 0);
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N)
    {
        uint32_t number = numbers[i];
        
        if (number % 2 == 0)
        {
            if (number % 3 != 0 && number % 5 != 0)
            {
                //@ assert number % 2 == 0 && number % 3 != 0 && number % 5 != 0;
                count += 1;
            }
        }
        
        i += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}

int main()
{
    return 0;
}
