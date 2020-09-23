project(test_suite)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_suite main.cpp MyTest.cpp ../src/PhotoRepository.cpp ../src/FlightDataLoader.cpp ../src/PhotoWriter.cpp ../src/CoordinateService.cpp)
