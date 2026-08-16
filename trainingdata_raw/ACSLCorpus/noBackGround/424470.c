/*@
    requires \valid(result);
    requires a >= 1 && a <= 20;
    requires b >= 1 && b <= 20;
    requires c >= 1 && c <= 20;
    requires d >= 1 && d <= 20;
    assigns *result;
    ensures *result == (a - c) * (b - d);
*/
void func(int a, int b, int c, int d, int *result)
{
    int diff_ac;
    int diff_bd;
    int temp_result;

    //@ assert ((a) >= 1 && (a) <= 20 &&         (b) >= 1 && (b) <= 20 &&         (c) >= 1 && (c) <= 20 &&         (d) >= 1 && (d) <= 20);
    
    diff_ac = a - c;
    //@ assert diff_ac == ((a) - (c));
    
    diff_bd = b - d;
    //@ assert diff_bd == ((b) - (d));
    
    //@ assert diff_ac >= -19 && diff_ac <= 19;
    //@ assert diff_bd >= -19 && diff_bd <= 19;
    
    //@ assert diff_ac >= -20 && diff_ac <= 20;
    //@ assert diff_bd >= -20 && diff_bd <= 20;
    
    temp_result = diff_ac * diff_bd;
    //@ assert temp_result == ((((a)) - ((c))) * (((b)) - ((d))));
    
    //@ assert temp_result >= -400 && temp_result <= 400;
    
    *result = temp_result;
    //@ assert *result == (a - c) * (b - d);
}
