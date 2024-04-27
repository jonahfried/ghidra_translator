
undefined _string_to_bool_from_cstr(char *param_1)

{
  int iVar1;
  undefined local_9;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: bool str is NULL and invalid in string_to_bool_cstr.\n");
    local_9 = 0;
  }
  else {
    iVar1 = _strcmp(param_1,"true");
    if (iVar1 == 0) {
      local_9 = 1;
    }
    else {
      iVar1 = _strcmp(param_1,"false");
      if (iVar1 == 0) {
        local_9 = 0;
      }
      else {
        local_9 = 0;
      }
    }
  }
  return local_9;
}

