cmake_minimum_required(VERSION 3.11.0)
project(PizzasTest)

# Enable testing
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Funghi.cpp 
    src/Margherita.cpp 
    src/Pizza.cpp 
    src/Pizzeria.cpp
)


# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}-ut
    src/Pizzeria.cpp
    src/Funghi.cpp 
    src/Margherita.cpp 
    src/Pizza.cpp 
    test/PizzeriaTest.cpp
)

target_link_libraries(${PROJECT_NAME}-ut gmock_main)

# Add the test
add_test(NAME ${PROJECT_NAME}-ut COMMAND ${PROJECT_NAME}-ut)