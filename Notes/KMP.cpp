vi kmppre(string& t){
  vi r(sz(t) + 1);
  r[0] = -1; int j = -1;
  fore(i,0,sz(t)){
    while(j >= 0 && t[i] != t[j])
      j = r[j];
    r[i+1] = ++j;
  }
  return r;
}

// Encontrar t en s
void kmp(string& s, string& t){
  int j = 0; vi b = kmppre(t);
  fore(i,0,sz(s)){
    while(j >= 0 && s[i] != t[j])
      j = b[j];
    if(++j == sz(t))
      cout << "Match en index " << i-j+1 << ENDL;
    j = b[j];
  }
}