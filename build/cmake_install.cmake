# Install script for directory: /home/bart/Documents/OOP_C++/tw3720tu.2017

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/00-git-bisect/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/01-hello/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/02-variables-constants/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/03-pointers/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/04-passing-arguments/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/07-dot-product-struct/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/08-dot-product-struct2/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/09-copy-move/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/10-integration/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/11-polymorphism/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/12-auto-decltype/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/13-templates/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/14-templates-partial-specialisation/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/15-traits/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/16-templates-sfinae/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/17-templates-sfinae2/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/18-complex-conjugate/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/20-containers/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/21-algorithm/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/22-stack-queue/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/23-linalg/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/24-maps/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H01-swap/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H03-reverse-engineering/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H04-points-triangles/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H05-copy-move/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H06-derivatives/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H09-symbolic-differentiation/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H10-add-vectors/cmake_install.cmake")
  include("/home/bart/Documents/OOP_C++/tw3720tu.2017/build/H11-heat-equation/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/bart/Documents/OOP_C++/tw3720tu.2017/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
