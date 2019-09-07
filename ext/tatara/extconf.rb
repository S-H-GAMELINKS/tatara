
require "mkmf-rice"

$CXXFLAGS = '-Ofast -mtune=native -march=native -mfpmath=both'

create_makefile("tatara/tatara") 