add_library(detours STATIC
        ./src/detours.cpp
        ./src/modules.cpp
        ./src/disasm.cpp
        ./src/image.cpp
        ./src/creatwth.cpp
        ./src/disolx86.cpp
        )
target_include_directories(detours PUBLIC ./src)