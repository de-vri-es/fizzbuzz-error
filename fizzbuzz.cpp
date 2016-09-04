// Compile time fizzbuzz.
// You can find the result in the compiler error.

template<int>
struct n {};
struct fizz {};
struct buzz {};
struct fizzbuzz {};

template<int x, bool, bool>
struct fizzbuzz_n_impl {
       using type = n<x>;
};

template<int x>
struct fizzbuzz_n_impl<x, true, false> {
       using type = fizz;
};

template<int x>
struct fizzbuzz_n_impl<x, false, true> {
       using type = buzz;
};

template<int x>
struct fizzbuzz_n_impl<x, true, true> {
       using type = fizzbuzz;
};

template<int x>
using fizzbuzz_n = typename fizzbuzz_n_impl<x, x % 3 == 0, x % 5 == 0>::type;

template<typename...> struct result {};

template<int n, typename... R>
struct fizzbuzz_to_impl {
       using type = typename fizzbuzz_to_impl<n - 1, fizzbuzz_n<n>, R...>::type;
};

template<typename... R>
struct fizzbuzz_to_impl<0, R...> {
       using type = result<R...>;
};

template<int n>
using fizzbuzz_to = typename fizzbuzz_to_impl<n>::type;

int x = fizzbuzz_to<100>();
