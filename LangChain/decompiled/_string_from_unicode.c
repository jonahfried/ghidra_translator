
undefined8 _string_from_unicode(wchar_t *param_1)

{
  size_t sVar1;
  char *pcVar2;
  undefined8 local_10;
  
  if (param_1 == (wchar_t *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input wide string is NULL in string_from_unicode.\n");
    local_10 = 0;
  }
  else {
    sVar1 = _wcstombs((char *)0x0,param_1,0);
    if (sVar1 == 0xffffffffffffffff) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Conversion failed in string_from_unicode.\n");
      local_10 = 0;
    }
    else {
      pcVar2 = (char *)_malloc(sVar1 + 1);
      if (pcVar2 == (char *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_from_unicode.\n");
        local_10 = 0;
      }
      else {
        _wcstombs(pcVar2,param_1,sVar1 + 1);
        local_10 = _string_create(pcVar2);
        _free(pcVar2);
      }
    }
  }
  return local_10;
}

