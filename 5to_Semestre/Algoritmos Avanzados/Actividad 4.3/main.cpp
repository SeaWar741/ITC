//Actividad 3.4 Implementación de "Graph coloring"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

//struct for point
struct Point {
    int x;
    int y;
};

//function to sort vector of points by x-coordinate and y-coordinate
//O((N log N)^2) 
void sort_points(vector<Point> &points) {
    //sort points by x-coordinate
    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.x < b.x;
    });
    //sort points by y-coordinate
    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.y < b.y;
    });
}

//function to calculate distance between two points
//O(1)
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//function to calculate minimum distance between three points
//O(1)
double min_distance(Point a, Point b, Point c) {
    return min(min(distance(a, b), distance(a, c)), distance(b, c));
}

//function to find miniumum
//O(1)
double min(double a, double b) {
    return a < b ? a : b;
}

//function to calculate minimum global distance between points
//O(N^3)
double min_global_distance(vector<Point> points) {
    double min_distance_val = INT_MAX;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            for (int k = j + 1; k < points.size(); k++) {
                min_distance_val = min(min_distance_val, min_distance(points[i], points[j], points[k]));
            }
        }
    }
    return min_distance_val;
}

//function to return vector of distances
//O(N^2)
vector<double> distances(vector<Point> points) {
    vector<double> distances;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            distances.push_back(distance(points[i], points[j]));
        }
    }
    return distances;
}

//function to find points inside limits
//O(N^2)
vector<Point> points_inside_limits(vector<Point> points, double min_distance_val) {
    vector<Point> points_inside_limits;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (distance(points[i], points[j]) <= min_distance_val) {
                points_inside_limits.push_back(points[i]);
                points_inside_limits.push_back(points[j]);
            }
        }
    }
    return points_inside_limits;
}

//function to merge two vectors of points
//O(N)
vector<Point> merge_vectors(vector<Point> points1, vector<Point> points2) {
    vector<Point> merged_points;
    for (int i = 0; i < points1.size(); i++) {
        merged_points.push_back(points1[i]);
    }
    for (int i = 0; i < points2.size(); i++) {
        merged_points.push_back(points2[i]);
    }
    return merged_points;
}

//function to find nearest pair points
//O(n log n)
void nearest_pair_points(vector<Point> &points) {
    //sort points by x-coordinate
    sort_points(points);
    //initialize minimum distance
    double min_dist = INT_MAX;
    
    //base cases
    if(points.size() == 1) {
        min_dist = 0.0;
        return;
    }
    if(points.size() == 2) {
        min_dist = distance(points[0], points[1]);
        return;
    }
    if(points.size() == 3) {
        min_dist = min_distance(points[0], points[1], points[2]);
        return;
    }
    //divide points into two halves
    int mid = points.size() / 2;
    //initialize left and right vectors
    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());
    
    //vector of distances
    double delta_left = min_global_distance(left);
    double delta_right = min_global_distance(right);
    double delta = min(delta_left, delta_right);

    //vector of points inside limits
    vector<Point> points_inside_limits_left = points_inside_limits(left, delta);
    vector<Point> points_inside_limits_right = points_inside_limits(right, delta);
    vector<Point> points_inside_limits = merge_vectors(points_inside_limits_left, points_inside_limits_right);

    //compare points inside limits and find minimum distance
    for (int i = 0; i < points_inside_limits.size(); i++) {
        for (int j = i + 1; j < points_inside_limits.size(); j++) {
            min_dist = min(min_dist, distance(points_inside_limits[i], points_inside_limits[j]));
        }
    }

    //print minimum distance
    cout << "La distancia mas corta es: "<< min_dist << endl;
}


int main(){
    //read number of points
    int n;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementacion búsqueda geométrica\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el numero de puntos> ";
    cin >> n;
    //read points
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    //find nearest pair of points
    nearest_pair_points(points);

    return 0;
}
