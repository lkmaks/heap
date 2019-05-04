# heap


This is a project for c++ course which is modified (in tihs branch) for techprog homework.
Added file main.cpp and renamed testing executable to run_tests; Now there are 2 executables after building.


Heap lab work for DIHT MIPT (2018, 1 sem)

time_results.txt contains time measurements on my pc.
Tests directory contains files with tests written with
GoogleTest framework.

In order to run tests, main.cpp should be executed and
googletest framework (https://github.com/google/googletest)
should be put in a directory 'lib' in the root of the project.
Tests on time are disabled, to enable them erase DISABLED_ prefix
before test names. 

STL is not used in project, excluding cstdlib for
size_t type, some exceptions (std::logic_error,
std::invalid_argument, etc.) and priority_queue class for testing.
