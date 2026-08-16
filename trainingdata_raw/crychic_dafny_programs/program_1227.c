// Generated C + ACSL

/*@
  predicate VerifyCheckBlood(integer id, char *b, integer b_len, integer v, boolean s, integer u, char *l, integer l_len, char *dn, integer dn_len, char *de, integer de_len, boolean o) =
    id > 0 && v > 0 && u > 0 &&
    b_len > 0 && l_len > 0 && dn_len > 0 && de_len > 0 &&
    o == \false;
*/

/*@
    requires b != \null;
    requires b_len >= 0;
    requires \valid_read(b + (0 .. b_len-1));
    requires l != \null;
    requires l_len >= 0;
    requires \valid_read(l + (0 .. l_len-1));
    requires dn != \null;
    requires dn_len >= 0;
    requires \valid_read(dn + (0 .. dn_len-1));
    requires de != \null;
    requires de_len >= 0;
    requires \valid_read(de + (0 .. de_len-1));
    assigns \nothing;
*/
void CheckBlood(int id, char* b, int b_len, int v, int s, int u, char* l, int l_len, char* dn, int dn_len, char* de, int de_len)
{
  int o = 0;
  /*@ assert o >= 0 && o <= 2147483647; */
  int valid_blood = 1;
  /*@ assert valid_blood >= 0 && valid_blood <= 2147483647; */
  if (((((((((b != "A+") && (b != "A-")) && (b != "B+")) && (b != "B-")) && (b != "AB+")) && (b != "AB-")) && (b != "O+")) && (b != "O-")))
  {
    valid_blood = 0;
  }
  else
  if (((((((id <= 0) || (v <= 0)) || (u <= 0)) || (l_len == 0)) || (dn_len == 0)) || (de_len == 0)))
  {
    valid_blood = 0;
  }
  /*@ assert (o == 0); */
}