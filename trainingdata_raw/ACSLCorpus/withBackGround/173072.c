#include <stdbool.h>

/*@ predicate is_leap_year(integer year) =
      ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
*/

/*@ predicate is_odd(integer n) =
      n % 2 != 0;
*/

/*@ predicate is_even(integer n) =
      n % 2 == 0;
*/

/*@ lemma leap_year_2020:
      is_leap_year(2020);
*/

/*@ lemma not_leap_year_1900:
      !is_leap_year(1900);
*/

/*@ lemma odd_1:
      is_odd(1);
*/

/*@ lemma not_odd_2:
      !is_odd(2);
*/

/*@ lemma even_2:
      is_even(2);
*/

/*@ lemma not_even_1:
      !is_even(1);
*/

/*@ requires year > 0;
    ensures \result == (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    assigns \nothing;
*/
bool is_leap_year_executable(unsigned int year) {
    bool result;
    result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    //@ assert result == (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    return result;
}

/*@ requires n >= 0;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd_executable(unsigned int n) {
    bool result;
    result = (n % 2 != 0);
    //@ assert result == (n % 2 != 0);
    return result;
}

/*@ requires n >= 0;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool is_even_executable(unsigned int n) {
    bool result;
    result = (n % 2 == 0);
    //@ assert result == (n % 2 == 0);
    return result;
}
