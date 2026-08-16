// Generated C + ACSL

/*@
  predicate VerifyCheckBlood(integer id, char *b, integer v, integer s, integer u, char *l, char *dn, char *de, integer o) =
    id > 0 && v > 0 && u > 0 && s >= 0 && o == 0;
*/

/*@
    requires b != \null;
    requires \valid_read(b + (0 .. b_len-1));
    requires l != \null;
    requires \valid_read(l + (0 .. l_len-1));
    requires dn != \null;
    requires \valid_read(dn + (0 .. dn_len-1));
    requires de != \null;
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
  if (((((((id <= 0) || (v <= 0)) || (u <= 0)) || (l == "")) || (dn == "")) || (de == "")))
  {
    valid_blood = 0;
  }
  /*@ assert (o == 0); */
}