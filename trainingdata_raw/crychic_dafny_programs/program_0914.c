// Generated C + ACSL

/*@
    requires ram != \null;
    requires ram_len > 0;
    requires \valid_read(ram + (0 .. ram_len-1));
    requires cpu != \null;
    requires cpu_len > 0;
    requires \valid_read(cpu + (0 .. cpu_len-1));
    assigns \nothing;
*/
void LaptopNuovo(char* ram, int ram_len, char* cpu, int cpu_len, int antivirus)
{
  /* unsupported stmt: print "Il nuovo laptop avrà le seguenti caratteristiche: \n"; */
  /* unsupported stmt: print "Ram: ", ram, "\n"; */
  /* unsupported stmt: print "CPU: ", cpu, "\n"; */
  if (antivirus)
  {
    /* unsupported stmt: print "Sei in possesso anche di un antivirus\n"; */
  }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  LaptopNuovo("8GB", 4, "Intel i5", 9, 1);;
}