
long _string_length_utf8(char *param_1)

{
  long local_20;
  char *local_18;
  long local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str is null in string_length_cstr.\n");
    local_10 = 0;
  }
  else {
    local_20 = 0;
    for (local_18 = param_1; *local_18 != '\0'; local_18 = local_18 + 1) {
      if (((int)*local_18 & 0xc0U) != 0x80) {
        local_20 = local_20 + 1;
      }
    }
    local_10 = local_20;
  }
  return local_10;
}

