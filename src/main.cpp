#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using std::cout;
using std::endl;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::make_tuple;
using std::string;
using std::tuple;
using std::vector;

int main() {
    vector<tuple<time_t, string>> ps = vector<tuple<time_t, string>> {
        make_tuple(1539096140, "C:\\MyPhotos\\photo1.jpg"),
        make_tuple(1539096146, "C:\\MyPhotos\\photo5.jpg"),
        make_tuple(1539096143, "C:\\MyPhotos\\photo2.jpg"),
        make_tuple(1539096150, "C:\\MyPhotos\\photo3.jpg"),
        make_tuple(1539096145, "C:\\MyPhotos\\photo4.jpg"),
    };
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Photo list (timestamp | path)" << endl;
    cout << "-----------------------------" << endl;
    cout << std::get<0>(ps.at(0)) << " | " << std::get<1>(ps.at(0)) << endl;
    cout << std::get<0>(ps.at(1)) << " | " << std::get<1>(ps.at(1)) << endl;
    cout << std::get<0>(ps.at(2)) << " | " << std::get<1>(ps.at(2)) << endl;
    cout << std::get<0>(ps.at(3)) << " | " << std::get<1>(ps.at(3)) << endl;
    cout << std::get<0>(ps.at(4)) << " | " << std::get<1>(ps.at(4)) << endl;
    cout << endl;

    ifstream infile("../../resources/flight-data2.bin", ios::binary);
    time_t t1;
    time_t t2;
    time_t t3;
    time_t t4;
    time_t t5;
    double la1;
    double la2;
    double la3;
    double la4;
    double la5;
    double lo1;
    double lo2;
    double lo3;
    double lo4;
    double lo5;
    double a1;
    double a2;
    double a3;
    double a4;
    double a5;
    infile.read(reinterpret_cast<char*>(&t1), sizeof(time_t));
    infile.read(reinterpret_cast<char*>(&la1), sizeof(double));
    infile.read(reinterpret_cast<char*>(&lo1), sizeof(double));
    infile.read(reinterpret_cast<char*>(&a1), sizeof(double));
    infile.read(reinterpret_cast<char*>(&t2), sizeof(time_t));
    infile.read(reinterpret_cast<char*>(&la2), sizeof(double));
    infile.read(reinterpret_cast<char*>(&lo2), sizeof(double));
    infile.read(reinterpret_cast<char*>(&a2), sizeof(double));
    infile.read(reinterpret_cast<char*>(&t3), sizeof(time_t));
    infile.read(reinterpret_cast<char*>(&la3), sizeof(double));
    infile.read(reinterpret_cast<char*>(&lo3), sizeof(double));
    infile.read(reinterpret_cast<char*>(&a3), sizeof(double));
    infile.read(reinterpret_cast<char*>(&t4), sizeof(time_t));
    infile.read(reinterpret_cast<char*>(&la4), sizeof(double));
    infile.read(reinterpret_cast<char*>(&lo4), sizeof(double));
    infile.read(reinterpret_cast<char*>(&a4), sizeof(double));
    infile.read(reinterpret_cast<char*>(&t5), sizeof(time_t));
    infile.read(reinterpret_cast<char*>(&la5), sizeof(double));
    infile.read(reinterpret_cast<char*>(&lo5), sizeof(double));
    infile.read(reinterpret_cast<char*>(&a5), sizeof(double));
    infile.close();
    cout << "---------------------------------------------------------" << endl;
    cout << "Flight data (timestamp | latitude | longitude | altitude)" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << t1 << " | " << la1 << " | " << lo1 << " | " << a1 << endl;
    cout << t2 << " | " << la2 << " | " << lo2 << " | " << a2 << endl;
    cout << t3 << " | " << la3 << " | " << lo3 << " | " << a3 << endl;
    cout << t4 << " | " << la4 << " | " << lo4 << " | " << a4 << endl;
    cout << t5 << " | " << la5 << " | " << lo5 << " | " << a5 << endl;
    cout << endl;

    cout << "--------------------------------" << endl;
    cout << "Matching photos with coordinates" << endl;
    cout << "--------------------------------" << endl;
    tuple<string, double, double, double> matched1;
    tuple<string, double, double, double> matched2;
    tuple<string, double, double, double> matched3;
    tuple<string, double, double, double> matched4;
    tuple<string, double, double, double> matched5;
    if (t1 == std::get<0>(ps.at(0))) {
        matched1 = make_tuple(std::get<1>(ps.at(0)), la1, lo1, a1);
    }
    if (t1 == std::get<0>(ps.at(1))) {
        matched1 = make_tuple(std::get<1>(ps.at(1)), la1, lo1, a1);
    }
    if (t1 == std::get<0>(ps.at(2))) {
        matched1 = make_tuple(std::get<1>(ps.at(2)), la1, lo1, a1);
    }
    if (t1 == std::get<0>(ps.at(3))) {
        matched1 = make_tuple(std::get<1>(ps.at(3)), la1, lo1, a1);
    }
    if (t1 == std::get<0>(ps.at(4))) {
        matched1 = make_tuple(std::get<1>(ps.at(4)), la1, lo1, a1);
    }
    if (t2 == std::get<0>(ps.at(0))) {
        matched2 = make_tuple(std::get<1>(ps.at(0)), la2, lo2, a2);
    }
    if (t2 == std::get<0>(ps.at(1))) {
        matched2 = make_tuple(std::get<1>(ps.at(1)), la2, lo2, a2);
    }
    if (t2 == std::get<0>(ps.at(2))) {
        matched2 = make_tuple(std::get<1>(ps.at(2)), la2, lo2, a2);
    }
    if (t2 == std::get<0>(ps.at(3))) {
        matched2 = make_tuple(std::get<1>(ps.at(3)), la2, lo2, a2);
    }
    if (t2 == std::get<0>(ps.at(4))) {
        matched2 = make_tuple(std::get<1>(ps.at(4)), la2, lo2, a2);
    }
    if (t3 == std::get<0>(ps.at(0))) {
        matched3 = make_tuple(std::get<1>(ps.at(0)), la3, lo3, a3);
    }
    if (t3 == std::get<0>(ps.at(1))) {
        matched3 = make_tuple(std::get<1>(ps.at(1)), la3, lo3, a3);
    }
    if (t3 == std::get<0>(ps.at(2))) {
        matched3 = make_tuple(std::get<1>(ps.at(2)), la3, lo3, a3);
    }
    if (t3 == std::get<0>(ps.at(3))) {
        matched3 = make_tuple(std::get<1>(ps.at(3)), la3, lo3, a3);
    }
    if (t3 == std::get<0>(ps.at(4))) {
        matched3 = make_tuple(std::get<1>(ps.at(4)), la3, lo3, a3);
    }
    if (t4 == std::get<0>(ps.at(0))) {
        matched4 = make_tuple(std::get<1>(ps.at(0)), la4, lo4, a4);
    }
    if (t4 == std::get<0>(ps.at(1))) {
        matched4 = make_tuple(std::get<1>(ps.at(1)), la4, lo4, a4);
    }
    if (t4 == std::get<0>(ps.at(2))) {
        matched4 = make_tuple(std::get<1>(ps.at(2)), la4, lo4, a4);
    }
    if (t4 == std::get<0>(ps.at(3))) {
        matched4 = make_tuple(std::get<1>(ps.at(3)), la4, lo4, a4);
    }
    if (t4 == std::get<0>(ps.at(4))) {
        matched4 = make_tuple(std::get<1>(ps.at(4)), la4, lo4, a4);
    }
    if (t5 == std::get<0>(ps.at(0))) {
        matched5 = make_tuple(std::get<1>(ps.at(0)), la5, lo5, a5);
    }
    if (t5 == std::get<0>(ps.at(1))) {
        matched5 = make_tuple(std::get<1>(ps.at(1)), la5, lo5, a5);
    }
    if (t5 == std::get<0>(ps.at(2))) {
        matched5 = make_tuple(std::get<1>(ps.at(2)), la5, lo5, a5);
    }
    if (t5 == std::get<0>(ps.at(3))) {
        matched5 = make_tuple(std::get<1>(ps.at(3)), la5, lo5, a5);
    }
    if (t5 == std::get<0>(ps.at(4))) {
        matched5 = make_tuple(std::get<1>(ps.at(4)), la5, lo5, a5);
    }
    cout << "Matching done!" << endl;
    cout << endl;

    cout << "--------------------------------------" << endl;
    cout << "Writing GPS coordinates to image files" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Writing (latitude " << std::get<2>(matched1) << ", longitude " << std::get<1>(matched1) << ", altitude " << std::get<3>(matched1) << ") to \"" << std::get<0>(matched1) << "\"" <<  endl;
    cout << "Writing (latitude " << std::get<2>(matched2) << ", longitude " << std::get<1>(matched2) << ", altitude " << std::get<3>(matched2) << ") to \"" << std::get<0>(matched2) << "\"" << endl;
    cout << "Writing (latitude " << std::get<2>(matched3) << ", longitude " << std::get<1>(matched3) << ", altitude " << std::get<3>(matched3) << ") to \"" << std::get<0>(matched3) << "\"" << endl;
    cout << "Writing (latitude " << std::get<2>(matched4) << ", longitude " << std::get<1>(matched4) << ", altitude " << std::get<3>(matched4) << ") to \"" << std::get<0>(matched4) << "\"" << endl;
    cout << "Writing (latitude " << std::get<2>(matched5) << ", longitude " << std::get<1>(matched5) << ", altitude " << std::get<3>(matched5) << ") to \"" << std::get<0>(matched5) << "\"" << endl;
    cout << endl;

    return 0;
}
