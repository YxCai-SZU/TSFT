#include <stdbool.h>

/*@ requires 1 <= input <= 9;
    ensures \result == true <==> ((input) == 3 || (input) == 5 || (input) == 7);
    assigns \nothing; */
bool func(int input)
{
    bool result;
    
    //@ assert 1 <= input <= 9;
    
    switch(input)
    {
        case 3:
        case 5:
        case 7:
            //@ assert ((input) == 3 || (input) == 5 || (input) == 7);
            result = true;
            break;
            
        default:
            //@ assert !((input) == 3 || (input) == 5 || (input) == 7);
            result = false;
            break;
    }
    
    //@ assert result == true <==> ((input) == 3 || (input) == 5 || (input) == 7);
    return result;
}
