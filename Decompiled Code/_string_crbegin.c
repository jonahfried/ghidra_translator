
long _string_crbegin(long *param_1)

{
  long local_10;
  
  if (((param_1 == (long *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input, uninitialized, or empty String in string_crbegin function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1] + -1;
  }
  return local_10;
}

