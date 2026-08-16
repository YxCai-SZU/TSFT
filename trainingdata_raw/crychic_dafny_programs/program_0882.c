// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int Context(const char* name);

/*@
    assigns \nothing;
    ensures \result != 0;
    ensures \result >= 0 && \result <= 2147483647;
*/
int Response(const char* path, int context);

/*@
    requires request != 0;
    assigns \nothing;
    ensures \result != 0;
*/
int home(int request)
{
  int context = Context("Ian Wehmeyer");
  /*@ assert context != 0; */
  
  int response = Response("stockapp1/home.html", context);
  /*@ assert response != 0; */
  /*@ assert response >= 0 && response <= 2147483647; */
  
  return response;  // Dafny implicit return
}