
int _string_compare(char **param_1,char **param_2)

{
  int local_c;
  
  if ((param_1 == (char **)0x0) || (param_2 == (char **)0x0)) {
    if (param_1 == param_2) {
      local_c = 0;
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: One or both String objects are NULL in string_compare.\n");
      local_c = 1;
      if (param_1 == (char **)0x0) {
        local_c = -1;
      }
    }
  }
  else {
    local_c = _strcmp(*param_1,*param_2);
  }
  return local_c;
}

