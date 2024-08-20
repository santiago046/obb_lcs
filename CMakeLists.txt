cmake_minimum_required(VERSION 3.12)

project(obb_lcs
        VERSION 2.0
        DESCRIPTION "Fork of https://github.com/Sergeanur/obb_lcs with modifications for Linux compatibility."
        HOMEPAGE_URL "htpps://github.com/santiago046/obb_lcs"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(common OBJECT
            src/crc32.cpp
            src/dictionary.cpp
            src/WadFile.cpp
            src/utils_win32.cpp
)

add_executable(makeobb_lcs
               src/makeobb_lcs.cpp
               $<TARGET_OBJECTS:common>
)

add_executable(obbdec_lcs
               src/obbdec_lcs.cpp
               $<TARGET_OBJECTS:common>
)

install(TARGETS
        makeobb_lcs
        obbdec_lcs
        DESTINATION bin
)

install(FILES
        src/dictionary.txt
        DESTINATION bin
)
