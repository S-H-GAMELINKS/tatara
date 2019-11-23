
require "mkmf"

$CXXFLAGS = '-Ofast -mtune=native -march=native -mfpmath=both -std=c++17'

create_makefile("tatara/tatara") 