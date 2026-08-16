#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(list1+(0..len-1)) && \valid(list2+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true <==> (\forall size_t i; 0 <= i < (len) ==>
            ((list1)[i] == (element) ==> (list2)[i] == (element)));
*/
bool check_element_list(unsigned int *list1, unsigned int *list2,
                        size_t len, unsigned int element)
{
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==>
            (list1[j] == element ==> list2[j] == element);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert i < len;
        if (list1[i] == element && list2[i] != element)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main(void)
{
    return 0;
}
