export prefix=$(pwd)
./bootstrap.sh
./configure --prefix=$prefix/.libs --libdir=$prefix/.libs/lib64 --enable-static=yes --enable-shared=no
make -j
