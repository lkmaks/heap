# heap
Heap lab work for DIHT MIPT (2018, 1 sem)

time_results.txt contains time measurements on my pc. Tests directory contains files with tests written with
GoogleTest framework.

In order to run tests, main.cpp should be executed and
googletest framework (https://github.com/google/googletest)
should be put in a directory 'lib' in the root of the project. 

STL is not used in project, excluding cstdlib for
size_t type, some exceptions (std::logic_error,
std::invalid_argument, etc.) and priority_queue class for testing.
