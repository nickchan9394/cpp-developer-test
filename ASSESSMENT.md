# Desktop C++ Developer Technical Test

## Context

mdGeoSuite is an application used for post flight data processing. Once a flight is complete, we are able to fetch a 
flight data file from the drone using Bluetooth. This data file is a binary file.

One of the product owner's requirement for the application is to be able to read the flight data from this file and 
write the GPS coordinates (latitude, longitude, altitude) to a corresponding image file (taken by a camera installed 
underneath the drone).

## Directives

In this repository, we provide a working proof of concept on how to complete this task. Look at the application's main
function to see it in action.

While this iteration is solving our problem, the code is very fragile and hard to maintain. What we ask from you, for
this technical test, is to use it as a starting point and refactor it in an `Object Oriented` way to make it less 
fragile, easier to maintain and easier to understand.

Additional Notes:

- Two flight data files are provided so you can test your solution with more than one flight.
- As you can see in the provided example, the process of writing GPS coordinates simply outputs what would be written in
an actual image file's header. No need to implement a library that would actually write EXIF data to an image file. A 
simple `cout` is enough for now.
- The provided example outputs (`cout`) log message for every steps of the process. These were set up to help you 
understand all the solution steps. It is not mandatory to output those in your solution (only output the results, as 
mentioned in the previous bullet).

## Acceptance Criteria

1. The provided solution must comply with C++14 standards.
2. The provided solution must be CMake compatible.
3. The submitted solution must include an improved OOP design architecture.
4. The submitted solution must provide a way to test the whole feature. 

## Send Us Your Solution

Once you complete your task and you ready to send us your solution, please send us a zip file of your complete solution.
