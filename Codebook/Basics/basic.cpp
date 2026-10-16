// ============================================================
//                       Common STL & Bit Utils
// ============================================================

// # some functions

upper_bound(iter_front, iter_end, target);
// returns the iterator of the first element x > target

lower_bound(iter_front, iter_end, target);
// returns the iterator of the first element x >= target

next_permutation(iter_front, iter_end);
// returns the next lexographic order; replace the string / vector


// # string functions

s.substr(pos, len);
// substring starting at pos, length len

s.find(target);
// first occurrence, string::npos if not found

s.rfind(target);
// last occurrence, string::npos if not found

reverse(s.begin(), s.end());
// reverse the string

sort(s.begin(), s.end());
// sort characters

stoll(s);
// string -> long long

stoi(s);
// string -> int

to_string(x);
// number -> string


// # input output related

ios::sync_with_stdio(false);
cin.tie(nullptr);
// fast io

cout << fixed << setprecision(10) << ans;
// output the last i decimal places


// # custom sort

// custom sort function returns 1 if a is at the front of b
sort(v.begin(), v.end(), [](const type a, const type b){
    // compare function
});

struct custom_struct{
    bool operator < (const type &b) const {
        // your comparison
    }
};


// # bit functions

__builtin_popcount(x);
// total number of bit 1 (unsigned int)

__builtin_popcountll(x);
// total number of bit 1 (unsigned long long)

__builtin_clz(x);
// leading 0 count (unsigned int)

__builtin_clzll(x);
// leading 0 count (unsigned long long)

__builtin_ctz(x);
// trailing 0 count (unsigned int)

__builtin_ctzll(x);
// trailing 0 count (unsigned long long)

__builtin_parity(x);
// parity of bit 1 (unsigned int)

__builtin_parityll(x);
// parity of bit 1 (unsigned long long)
// the function changes int -> unsigned int and long long -> unsigned long long


// # bit operations

mask |= (1LL << k);
// set kth bit to 1

mask &= ~(1LL << k);
// remove kth bit 

mask ^= (1LL << k);
// flip kth bit

(mask >> k) & 1LL;
// check if kth bit is 1

mask & -mask;
// lowbit

mask &= mask - 1;
// remove lowbit

(x > 0 && (x & (x - 1)) == 0);
// check if x is a power of 2 (for x > 0)