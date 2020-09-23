#include "catch.hpp"
#include <iostream>
#include "../src/PhotoRepository.h"
#include "../src/FlightDataLoader.h"
#include "MockPhotoWriter.hpp"
#include "../src/CoordinateService.h"

using namespace std;

SCENARIO("I want to assert that ImageRepository can iterate its internal state") {
    GIVEN("two pictures got added to the repository") {
        PhotoRepository repo = PhotoRepository();
        repo.add(1539096140, "C:\\MyPhotos\\photo1.jpg");
        repo.add(1539096146, "C:\\MyPhotos\\photo5.jpg");

        WHEN("iterate the internal state") {
            string expected = "1539096140C:\\MyPhotos\\photo1.jpg1539096146C:\\MyPhotos\\photo5.jpg";
            string actual;

            for(vector<tuple<time_t, string>>::iterator ptr = repo.begin(); ptr < repo.end(); ptr++ ) {
                actual += ((std::to_string(std::get<0>(*ptr)) + std::get<1>(*ptr)));
            }

            THEN("the actual result equals expected result") {
                REQUIRE(expected == actual);
            }
        }
    }
}

SCENARIO("I want to assert that FlightDataLoader can load the data file") {
    GIVEN("data file got loaded") {
        FlightDataLoader loader = FlightDataLoader();
        loader.load("../../resources/flight-data1.bin");

        WHEN("iterate the data") {
            string expected = "153909614037.325500-17.16160026.787800153909614338.325300-18.98750022.156700153909614539.325100-19.55710025.985300153909614640.323700-20.56780028.758900153909615041.315800-31.12340021.565600153909615041.315800-31.12340021.565600";
            string actual;

            vector<Coordinate> coordinates = loader.getCoordinates();
            for(vector<Coordinate>::iterator ptr = coordinates.begin(); ptr < coordinates.end(); ptr++ ) {
                actual += (std::to_string((*ptr).timestamp) 
                            + std::to_string((*ptr).latitude)
                            + std::to_string((*ptr).longitude)
                            + std::to_string((*ptr).altitude));
            }

            THEN("the actual result equals expected result") {
                REQUIRE(expected == actual);
            }
        }
    }
}

SCENARIO("I want to assert that ImageRepository can match coordinates to photos") {
    GIVEN("coordinates and photos are prepared") {
        PhotoRepository repo = PhotoRepository();
        repo.add(1539096140, "C:\\MyPhotos\\photo1.jpg");
        repo.add(1539096146, "C:\\MyPhotos\\photo5.jpg");

        vector<Coordinate> coordinates = vector<Coordinate>{
            { 1539096140, 100, 101, 102 }
        };

        WHEN("match the coordinates") {
            string expectedPicPath = "C:\\MyPhotos\\photo1.jpg";
            double expectedLatitude = 100;
            double expectedLongitude = 101;
            double expectedAltitude = 102;

            vector<tuple<string,Coordinate>> matches = repo.match(coordinates);

            THEN("the actual result equals expected result") {
                REQUIRE(expectedPicPath == std::get<0>(matches.at(0)));
                REQUIRE(expectedLatitude == std::get<1>(matches.at(0)).latitude);
                REQUIRE(expectedLongitude == std::get<1>(matches.at(0)).longitude);
                REQUIRE(expectedAltitude == std::get<1>(matches.at(0)).altitude);
            }
        }
    }
}

SCENARIO("I want to assert that ImageService can write coordinates to photos") {
    GIVEN("service is prepared") {
        MockPhotoWriter *mockWriter = new MockPhotoWriter();

        CoordinateService coordinateService = CoordinateService(new PhotoRepository(), new FlightDataLoader(), mockWriter);

        WHEN("write coordinates to photos") {
            string expectedPicPath = "C:\\MyPhotos\\photo4.jpg";
            double expectedLatitude = 39.3251;
            double expectedLongitude = -19.5571;
            double expectedAltitude = 25.9853;

            coordinateService.writeCoordinatesToPhotos(
                "../../resources/flight-data1.bin",
                vector<tuple<time_t, string>> {
                    make_tuple(1539096145, "C:\\MyPhotos\\photo4.jpg")
            });

            THEN("the actual result equals expected result") {
                REQUIRE(expectedPicPath == std::get<0>(mockWriter->actual.at(0)));
                REQUIRE(expectedLatitude == std::get<1>(mockWriter->actual.at(0)).latitude);
                REQUIRE(expectedLongitude == std::get<1>(mockWriter->actual.at(0)).longitude);
                REQUIRE(expectedAltitude == std::get<1>(mockWriter->actual.at(0)).altitude);
            }
        }
    }
}