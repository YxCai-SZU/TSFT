/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0) && ((d) > 0);
    ensures \result == (a * b) * (c * d);
    assigns \nothing;
*/
int example_3(int a, int b, int c, int d)
{
    //@ assert a * b * c * d == (a * b) * (c * d);
    return (a * b) * (c * d);
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures *result_x_y <= 64 && *result_y_z <= 64 && *result_z_x <= 64;
    assigns *result_x_y, *result_y_z, *result_z_x;
*/
void example_4(unsigned int x, unsigned int y, unsigned int z,
               unsigned int* result_x_y,
               unsigned int* result_y_z,
               unsigned int* result_z_x)
{
    unsigned int temp_x_y;
    unsigned int temp_y_z;
    unsigned int temp_z_x;

    temp_x_y = x * y;
    //@ assert temp_x_y <= 64;

    temp_y_z = y * z;
    //@ assert temp_y_z <= 64;

    temp_z_x = z * x;
    //@ assert temp_z_x <= 64;

    *result_x_y = temp_x_y;
    *result_y_z = temp_y_z;
    *result_z_x = temp_z_x;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
