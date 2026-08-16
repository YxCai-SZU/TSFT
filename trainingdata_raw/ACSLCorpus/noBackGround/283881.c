#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(passengers + (0..len-1));
    requires (0 <= (k) <= (len));
    requires (\forall integer i; 0 <= i < (k) ==> (passengers)[i] >= (height));
    assigns \nothing;
    ensures \result <= k;
    ensures \forall integer i; 0 <= i < \result ==> passengers[i] >= height;
*/
size_t count_tall_enough_ride_passengers(unsigned int *passengers, size_t len, size_t k, unsigned int height)
{
    size_t count = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= k;
        loop invariant 0 <= count <= index;
        loop invariant \forall integer i; 0 <= i < count ==> passengers[i] >= height;
        loop invariant (\forall integer i; 0 <= i < (k) ==> (passengers)[i] >= (height));
        loop invariant (0 <= (k) <= (len));
        loop assigns index, count;
        loop variant k - index;
    */
    while (index < k && index < len)
    {
        unsigned int p_height = passengers[index];
        //@ assert p_height == passengers[index];
        
        if (p_height >= height)
        {
            //@ assert p_height >= height;
            count = count + 1;
        }
        //@ assert count <= index + 1;
        
        index = index + 1;
        //@ assert index <= k;
    }
    
    //@ assert count <= k;
    return count;
}

