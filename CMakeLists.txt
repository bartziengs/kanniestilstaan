# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: tw3720tu.2017
project (tw3720tu.2017)

# Prevent in-source builds 
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# Output message
message("Build all build targets of the course tw3720tu from 2017")

# Macro for generating log files for submitting assignments 
macro(add_assignment target src)
  add_custom_target(
    "${target}_assignment"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${src}" "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "=== Start Environment " >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "PROJECT_NAME = ${PROJECT_NAME}" >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_SYSTEM = ${CMAKE_SYSTEM}" >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_VERSION = ${CMAKE_VERSION}" >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}" >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}" >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "=== End Environment " >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "=== Start of output from execution of binary ${target}" >> "${target}.log"
    COMMAND ${target} >> "${target}.log"
    COMMAND ${CMAKE_COMMAND} -E echo "=== End of output from execution of binary ${target}" >> "${target}.log"
    DEPENDS ${target}
    VERBATIM
    )
endmacro()

# Enable CMake testing
include (CTest)
enable_testing()

# Enable Doxygen documentation
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile @ONLY)
    add_custom_target(doc
      ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc
    )
endif()

# Examples
add_subdirectory(00-git-bisect)
add_subdirectory(01-hello)
add_subdirectory(02-variables-constants)
add_subdirectory(03-pointers)
add_subdirectory(04-passing-arguments)
add_subdirectory(05-namespaces)
add_subdirectory(06-dot-product)
add_subdirectory(07-dot-product-struct)
add_subdirectory(08-dot-product-struct2)
add_subdirectory(09-copy-move)
add_subdirectory(10-integration)
add_subdirectory(11-polymorphism)
add_subdirectory(12-auto-decltype)
add_subdirectory(13-templates)
add_subdirectory(14-templates-partial-specialisation)
add_subdirectory(15-traits)
add_subdirectory(16-templates-sfinae)
add_subdirectory(17-templates-sfinae2)
add_subdirectory(18-complex-conjugate)
add_subdirectory(19-templates-variadic)
add_subdirectory(20-containers)
add_subdirectory(21-algorithm)
add_subdirectory(22-stack-queue)
add_subdirectory(23-linalg)
add_subdirectory(24-maps)

# Homework
add_subdirectory(H01-swap)
add_subdirectory(H02-arrays)
add_subdirectory(H03-reverse-engineering)
add_subdirectory(H04-points-triangles)
add_subdirectory(H05-copy-move)
add_subdirectory(H06-derivatives)
add_subdirectory(H07-templates)
add_subdirectory(H08-unit-converter)
add_subdirectory(H09-symbolic-differentiation)
add_subdirectory(H10-add-vectors)
add_subdirectory(H11-heat-equation)