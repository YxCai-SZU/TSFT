// Generated C + ACSL

#include <stddef.h>

/*@
    requires email != \null;
    requires email_len >= 0;
    requires \valid_read(email + (0 .. email_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (email_len >= 5 &&
         (\exists integer i; 0 <= i < email_len && email[i] == '@') &&
         (\exists integer j; 0 <= j < email_len && email[j] == '.'));
    ensures \result == 0 || \result == 1;
*/
int ValidEmail(char* email, int email_len)
{
  int has_at = 0;
  int has_dot = 0;

  /*@ loop invariant 0 <= i <= email_len;
      loop invariant has_at == 0 || has_at == 1;
      loop invariant has_dot == 0 || has_dot == 1;
      loop invariant has_at == 1 ==> 
          (\exists integer k; 0 <= k < i && email[k] == '@');
      loop invariant has_dot == 1 ==> 
          (\exists integer k; 0 <= k < i && email[k] == '.');
      loop assigns i, has_at, has_dot;
      loop variant email_len - i;
  */
  for (int i = 0; i < email_len; i++) {
    if (email[i] == '@') has_at = 1;
    if (email[i] == '.') has_dot = 1;
  }

  /*@ assert has_at == 1 ==> 
          (\exists integer k; 0 <= k < email_len && email[k] == '@'); */
  /*@ assert has_dot == 1 ==> 
          (\exists integer k; 0 <= k < email_len && email[k] == '.'); */

  return (email_len >= 5) && has_at && has_dot;
}

/*@
    requires first != \null;
    requires last != \null;
    requires email != \null;
    requires first_len > 0;
    requires last_len > 0;
    requires email_len >= 0;
    requires \valid_read(first + (0 .. first_len-1));
    requires \valid_read(last + (0 .. last_len-1));
    requires \valid_read(email + (0 .. email_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int CreateVisitor(char* first, int first_len, char* last, int last_len, char* email, int email_len)
{
  int visitor = 0;
  if ((((first_len > 0) && (last_len > 0)) && ValidEmail(email, email_len)))
  {
    visitor = 1;
  }
  else
  {
    visitor = 0;
    /*@ assert visitor >= 0 && visitor <= 2147483647; */
  }
  return visitor;
}

/*@
    requires firstName != \null;
    requires lastName != \null;
    requires email != \null;
    requires firstName_len >= 0;
    requires lastName_len >= 0;
    requires email_len >= 0;
    requires \valid_read(firstName + (0 .. firstName_len-1));
    requires \valid_read(lastName + (0 .. lastName_len-1));
    requires \valid_read(email + (0 .. email_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> firstName_len > 0 && lastName_len > 0;
*/
int IsValid(char* firstName, int firstName_len, char* lastName, int lastName_len, char* email, int email_len)
{
  int valid = (((firstName_len > 0) && (lastName_len > 0)) && ValidEmail(email, email_len));
  /*@ assert valid >= 0 && valid <= 2147483647; */
  return valid;
}