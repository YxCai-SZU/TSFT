#include <stdbool.h>


bool func(int k) {
    bool result = false;
    int n = 0;
    int temp_k = k;
    int product = 0;
    int new_k = 0;
    int temp_n = 0;

    
    while (temp_k >= 100) {
        //@ assert ((1 <= ((k)) && ((k)) <= 100000) &&         0 <= (n) && (n) <= (k) / 100 &&         (temp_k) == (k) - (n) * 100);
        temp_k -= 100;
        n += 1;
    }

    product = n * 100;
    temp_n = n;

    
    while (temp_n > 0) {
        //@ assert ((1 <= ((k)) && ((k)) <= 100000) &&         0 <= (temp_n) && (temp_n) <= (n) &&         (new_k) <= 105 * (n) &&         (new_k) >= 0 &&         (new_k) == 105 * ((n) - (temp_n)));
        new_k += 105;
        temp_n -= 1;
    }

    if (product <= k && k <= new_k) {
        result = true;
    }

    //@ assert result == true <==> (k / 100 * 100 <= k && k <= k / 100 * 105);
    return result;
}
