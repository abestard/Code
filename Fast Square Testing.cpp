//Fast Square Testing. An optimized test for square integers.
long long M;
void init_is_square(){
    rep(i,0,64) M |= 1ULL << (63-(i * i)%64);
}
inline bool is_square(long long x) {
    if ((M << x) >= 0) return false;
    int c =__builtin_ctz(x);
    if (c & 1) return false;
    x >>= c;
    if ((x&7) - 1) return false;
    long long r = sqrt(x);
    return r*r == x;
}
