add_executable(MakeTable MakeTable.cc)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )
add_library(MathFunctions
            mysqrt.cc
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h
            )
# Adding Usage Requirements for a Library
# anybody linking to MathFunctions needs to include the current source directory, while MathFunctions itself doesn't.
# INTERFACE means things that consumers require but the producer doesn't.
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          )

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)