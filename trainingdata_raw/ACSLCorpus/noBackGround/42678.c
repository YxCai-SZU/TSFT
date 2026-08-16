#include <limits.h>

/*@
    assigns \nothing;
    ensures \result == 0;
*/
int main()
{
    unsigned long long num_list_entries_per_node;
    unsigned int list_element_size;
    unsigned int metadata_size;
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    int result = 0;
    
    // Example 1 verification
    /*@
        assert (((list_element_size) + (metadata_size)) > 0 ==>
        (num_list_entries_per_node) <= (18446744073709551615ULL)/ ((list_element_size) + (metadata_size)) ==> 
        (num_list_entries_per_node) * ((list_element_size) + (metadata_size)) <= (18446744073709551615ULL));
    */
    
    // Example 2 verification
    /*@
        assert ((x) <= 1000 && (y) <= 1000 && (z) <= 1000 ==>
        (x) * (y) <= 1000000 &&
        (x) * (z) <= 1000000 &&
        (y) * (z) <= 1000000 &&
        (x) * (y) + (z) <= 2000000);
    */
    
    return result;
}
