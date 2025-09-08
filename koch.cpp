//This programs uses recursion to create coordinates for drawing a Koch curve, also known as the Koch snowflake
#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

struct Point {
    double x;
    double y;
};

ofstream fout("lines.txt");

void KochCurves (Point a, Point b, int detail) {
    if (detail == 0){
        fout << (int)round(a.x) << " " << (int)round(a.y) << " "
        << (int)round(b.x) << " " << (int)round(b.y) << "\n";
        return; 
    }
    Point p1, p2, peak;
    p1.x = a.x + (b.x - a.x) / 3.0;
    p1.y= a.y + (b.y - a.y) / 3.0;
    p2.x = a.x + 2.0 * (b.x - a.x) / 3.0;
    p2.y = a.y + 2.0 * (b.y - a.y) / 3.0;
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    //peak represents the top of the triangle created in the center of the line
    peak.x = p1.x + dx*0.5 - dy * sqrt(3.0) / 2; //we use 0.5 because of cos(60) and sqrt 3/2 because of sin(60) which defines the inclination of our triangle
    peak.y = p1.y + dy*0.5 + dx * sqrt(3.0) / 2;
    //recursive calls
    KochCurves(a, p1, detail - 1);
    KochCurves(p1, peak, detail - 1);   
    KochCurves(peak, p2, detail - 1);
    KochCurves(p2, b, detail - 1);

}  

int main(int argc, char*argv[]){
    if (argc != 6)
{
        cout << "Example: " << argv[0] << " x1 y1 x2 y2 detail" << endl;
        return -1;
    }
    auto start = high_resolution_clock::now(); // clock starts

    int iterations = stoi(argv[1]); //string to interger
    Point a{stod(argv[2]), stod(argv[3])}; //string to double
    Point b{stod(argv[4]), stod(argv[5])};
    
    if (a.x < 0 || a.x > 1024 || a.y < 0 || a.y > 1024 ||
        b.x < 0 || b.x > 1024 || b.y < 0 || b.y > 1024) {
        cout << "Coordinates must be between 0 and 1024" << endl;
        return -1;
    } //to make sure the coordinates fit in our canvas

    KochCurves(a, b, iterations);
    fout.close(); //to close the file!
    auto stop = high_resolution_clock::now(); // clock stops
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "-----------------------------------" << endl;
    cout << "Gael Cervantes (A01641482) - Sophia Lenero (A01639462) " << endl;
    cout << ", Time taken: " << duration.count() << " microseconds" << endl;
    return 0;

}