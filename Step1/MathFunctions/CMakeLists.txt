add_library(MathFunctions mysqrt.cc)
# Adding Usage Requirements for a Library
# anybody linking to MathFunctions needs to include the current source directory, while MathFunctions itself doesn't.
# INTERFACE means things that consumers require but the producer doesn't.
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)