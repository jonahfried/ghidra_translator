
long _string_base64_encode(long *param_1)

{
  ulong local_30;
  int local_28;
  int local_24;
  long local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_baes64_encode.\n");
    local_10 = 0;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_base64_encode.\n");
    local_10 = 0;
  }
  else {
    local_10 = _string_create("");
    local_24 = 0;
    local_28 = -6;
    for (local_30 = 0; local_30 < (ulong)param_1[1]; local_30 = local_30 + 1) {
      local_24 = local_24 * 0x100 + (uint)*(byte *)(*param_1 + local_30);
      for (local_28 = local_28 + 8; -1 < local_28; local_28 = local_28 + -6) {
        _string_push_back(local_10,(int)(char)_base64_chars
                                              [(int)(local_24 >> ((byte)local_28 & 0x1f) & 0x3f)]);
      }
    }
    if (-6 < local_28) {
      _string_push_back(local_10,(int)(char)_base64_chars
                                            [(int)((local_24 << 8) >> ((char)local_28 + 8U & 0x1f) &
                                                  0x3f)]);
    }
    while ((*(ulong *)(local_10 + 8) & 3) != 0) {
      _string_push_back(local_10,0x3d);
    }
  }
  return local_10;
}

