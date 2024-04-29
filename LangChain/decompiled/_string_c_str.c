
char * _string_c_str(char **param_1)

{
  char *local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid input in string_c_str function.\n");
    local_10 = "";
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Uninitialized String in string_c_str function.\n");
    local_10 = "";
  }
  else {
    local_10 = *param_1;
  }
  return local_10;
}

