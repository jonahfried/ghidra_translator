
long _string_crend(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_crend function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + -1;
  }
  return local_10;
}

