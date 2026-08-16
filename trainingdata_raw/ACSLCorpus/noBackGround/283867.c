#include <stdbool.h>
#include <stddef.h>

/*@
    requires (2 <= (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> (a)[i] % 2 == 0);
    assigns \nothing;
*/
bool func(size_t n, const int *a)
{
    size_t even = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= even <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= a[i] <= 1000000000;
        loop invariant 2 <= n <= 200000;
        loop invariant even == index <==> \forall integer i; 0 <= i < index ==> a[i] % 2 == 0;
        loop assigns index, even;
        loop variant n - index;
    */
    while (index < n)
    {
        int ai = a[index];
        if (ai % 2 == 0)
        {
            even += 1;
        }
        index += 1;
        
        //@ assert even == index <==> \forall integer i; 0 <= i < index ==> a[i] % 2 == 0;
    }
    
    //@ assert even == n <==> (\forall integer i; 0 <= i < (n) ==> (a)[i] % 2 == 0);
    return even == n;
}

int main(void)
{
    return 0;
}
