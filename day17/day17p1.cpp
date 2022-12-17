#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "shapes.hpp"

using namespace std;

vector<Point> tick(
        vector<Point> surface,
        Shape* currShape,
        char action
    ) {
    
    // write the logic to move the rock until no longer possible

}

int getHighestY(vector<Point> surface) {
    // cout << "getting called" << endl;
    int max = surface.at(0).y;
    for (int i = 1; i < surface.size(); i++) {
        if (surface.at(i).y >= max) {
            max = surface.at(i).y;
        }
    }
    return max;
}

int main() {

    ifstream inFS;

    inFS.open("./test.txt");

    if (!inFS.is_open()) { 
        cout << "could not open input file" << endl;    
        exit(1);
    }

    vector<Point> surface;

    // initialize surface
    for (int i = 0; i < 7; i++) {
        surface.push_back(Point(0, 0));
    }

    // initialize current max height
    int currMax = 0;

    int shape_i = 0;

    char currMove;
    // get initial state
    while (!inFS.eof()) {
        // get the current move
        inFS >> currMove;

        // get highest Y given current surface
        currMax = getHighestY(surface);

        // get shape, place it in simulation
        // and see how it affects the surface
        Shape* currShape;

        switch (shape_i % 5) {

            case 0:
                // cout << "creating HBar" << endl;
                currShape = new HBar(currMax);
                break;
            case 1:
                // cout << "creating Plus" << endl;
                currShape = new Plus(currMax);
                break;
            case 2:
                // cout << "creating BackL" << endl;
                currShape = new BackL(currMax);
                break;
            case 3:
                // cout << "creating VBar" << endl;
                currShape = new VBar(currMax);
                break;
            case 4:
                // cout << "creating Square" << endl;
                currShape = new Square(currMax);
                break;
            default:
                break;
        }

        // surface = updateSurface(surface, currShape);

        shape_i++;

        if (shape_i == 20) {
            break;
        }
    }

    return 0;
}