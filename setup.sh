./configure --disable-shared --prefix=$HOME/musl --exec-prefix=$HOME/musl_bin --syslibdir=$HOME/musl/lib
make && make install
