#include <stdbool.h>

/*@
    requires 0 <= kilowatt_hours <= 10000;
    ensures \result == 0 || \result == 1;
    ensures \result == ((kilowatt_hours) > 500 ? 1 : 0);
    assigns \nothing;
*/
int calculate_consumption(int kilowatt_hours)
{
    int result;
    
    if (kilowatt_hours > 500) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}

/*@
    requires 0 <= consumption && consumption <= 1;
    assigns \nothing;
*/
void print_electricity_bill(int consumption)
{
    //@ assert consumption == 0 || consumption == 1;
}

/*@
    assigns \nothing;
*/
int main()
{
    int consumption;
    
    consumption = calculate_consumption(600);
    //@ assert consumption == 0 || consumption == 1;
    print_electricity_bill(consumption);
    
    return 0;
}
