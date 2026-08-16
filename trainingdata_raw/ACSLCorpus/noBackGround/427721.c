/*@
    requires ((input) >= 1 && (len) >= (input));
    ensures \result >= 0 && \result <= input;
    assigns \nothing;
*/
int func(int input, int* nums, int len) {
    int current_length = 0;
    int index = 0;
    
    /*@
        loop invariant (0 <= (index) && (index) <= (len) && (index) <= (input) &&
        (current_length) >= 0 && (current_length) <= (index));
        loop invariant ((input) >= 1 && (len) >= (input));
        loop assigns current_length, index;
        loop variant input - index;
    */
    while (index < len && index < input) {
        int x = nums[index];
        if (x == 0) {
            current_length += 1;
        } else {
            current_length = 0;
        }
        index += 1;
    }
    
    //@ assert current_length >= 0 && current_length <= input;
    return current_length;
}
