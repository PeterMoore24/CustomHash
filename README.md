# CustomHash
The goal of this solution is to be able to hash or crack hashes specified by part 4 of assignment 4 for CSE365. The hash function takes input, hashes the input with md5 100 times, then with sha256 100 times, then with sha512 100 times.

In its first revision, it will probably just have the hash I need to crack hard-coded in, but eventually I'd like to expand it to be able to hash and crack based on character sets.

I wrote everything in main.cpp, feel free to use that code however you'd like.

I'm using code from zedwood.com to implement md5, sha256, and sha512, links here and liscences in those files.
md5: http://www.zedwood.com/article/cpp-md5-function
sha256: http://www.zedwood.com/article/cpp-sha256-function
sha512: http://www.zedwood.com/article/cpp-sha512-function
