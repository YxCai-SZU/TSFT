#include <stdbool.h>


bool func(int *numbers) {
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int index = 0;
    
    
    while (index < 3) {
        int value = numbers[index];
        
        //@ assert (1 <= (value) <= 100);
        
        if (index == 0) {
            sum1 = value;
        } else if (index == 1) {
            sum2 = value;
        } else if (index == 2) {
            sum3 = value;
        }
        
        index++;
    }
    
    //@ assert sum1 == numbers[0];
    //@ assert sum2 == numbers[1];
    //@ assert sum3 == numbers[2];
    
    //@ assert (1 <= (sum1) <= 100);
    //@ assert (1 <= (sum2) <= 100);
    //@ assert (1 <= (sum3) <= 100);
    
    //@ assert sum1 + sum2 <= 200;
    //@ assert sum2 + sum3 <= 200;
    //@ assert sum1 + sum3 <= 200;
    
    return (sum1 + sum2 == sum3) || 
           (sum2 + sum3 == sum1) || 
           (sum1 + sum3 == sum2);
}
