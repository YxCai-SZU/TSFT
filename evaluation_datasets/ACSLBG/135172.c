#include <stdbool.h>

/*@
    predicate valid_input(integer r, integer g, integer b) =
        1 <= r && r <= 9 &&
        1 <= g && g <= 9 &&
        1 <= b && b <= 9;

    logic integer compute_sum(integer r, integer g, integer b) =
        r * 100 + g * 10 + b;

    lemma sum_mod_preserved:
        \forall integer sum;
        (sum >= 0 ==> (sum % 4 == sum % 4)) &&
        (sum < 0 ==> ((-sum) % 4 == (-sum) % 4));
*/


bool func(int r, int g, int b)
{
    int sum;
    bool is_divisible;
    int abs_sum;
    int temp;

    sum = r * 100 + g * 10 + b;
    is_divisible = false;
    
    //@ assert valid_input(r, g, b);
    
    if (sum < 0) {
        abs_sum = -sum;
    } else {
        abs_sum = sum;
    }
    
    //@ assert abs_sum == (sum < 0 ? -sum : sum);
    
    temp = abs_sum;
    
    while (temp >= 4) {
        temp -= 4;
    }
    
    if (temp == 0) {
        is_divisible = true;
    }
    
    //@ assert is_divisible == (abs_sum % 4 == 0);
    
    return is_divisible;
}


int main() {
    return 0;
}
