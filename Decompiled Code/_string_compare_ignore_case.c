
int _string_compare_ignore_case(char **param_1,char **param_2)

{
  int local_c;
  
  if ((param_1 == (char **)0x0) || (param_2 == (char **)0x0)) {
    if (param_1 == param_2) {
      local_c = 0;
    }
    else {
      local_c = 1;
      if (param_1 == (char **)0x0) {
        local_c = -1;
      }
    }
  }
  else if ((*param_1 == (char *)0x0) || (*param_2 == (char *)0x0)) {
    if (*param_1 == *param_2) {
      local_c = 0;
    }
    else {
      local_c = 1;
      if (*param_1 == (char *)0x0) {
        local_c = -1;
      }
    }
  }
  else {
    local_c = _strcasecmp(*param_1,*param_2);
  }
  return local_c;
}

