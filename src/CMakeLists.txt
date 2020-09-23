project(technical_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(technical_test main.cpp PhotoRepository.cpp FlightDataLoader.cpp PhotoWriter.cpp CoordinateService.cpp)
