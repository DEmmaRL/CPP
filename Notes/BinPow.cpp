lli binpow(lli a, lli b) {
    if (b == 0)
        return 1;
    lli res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}