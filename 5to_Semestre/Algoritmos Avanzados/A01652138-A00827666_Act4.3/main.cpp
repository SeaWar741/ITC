//Actividad 4.3 Implementación búsqueda geométrica
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
    
    //minor operator
    int operator < (const Point& p) const { return x < p.x; };

    //equality operator
    bool operator == (const Point& p) const { return x == p.x && y == p.y; };

    //print operator
    friend ostream& operator << (ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

//function to calculate distance between two points
//input: point a and point b
//output: distance between a and b
//complexity: O(1)
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//function to calculate minimum distance between three points
//input: point a, point b and point c
//output: minimum distance between a, b and c
//complexity: O(1)
double min_distance(Point a, Point b, Point c) {
    return min(min(distance(a, b), distance(a, c)), distance(b, c));
}

//function to find miniumum
//input: two doubles
//output: minimum of two doubles
//complexity: O(1)
double min(double a, double b) {
    return a < b ? a : b;
}

//function to calculate minimum global distance between points
//input: vector of points
//output: minimum global distance between points
//complexity: O(N^3)
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
//input: vector of points
//output: vector of distances
//complexity: O(N^2)
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
//input: vector of points, minimum distance
//output: vector of points inside limits
//complexity: O(N^2)
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
//input: two vectors of points
//output: merged vector of points
//complexity: O(N)
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
//input: vector of points
//output: nearest pair points
//complexity: O(n log n)
void nearest_pair_points(vector<Point> &points) {
    //sort points by x-coordinate
    sort(points.begin(), points.end());

    //initialize minimum distance
    double min_dist = INT_MAX;
    
    //base cases
    if(points.size() == 1) {
        min_dist = 0.0;
        cout << "La distancia mas corta es: " << min_dist << endl;
        return;
    }
    if(points.size() == 2) {
        min_dist = distance(points[0], points[1]);
        cout << "La distancia mas corta es: " << min_dist << endl;
        return;
    }
    if(points.size() == 3) {
        min_dist = min_distance(points[0], points[1], points[2]);
        cout << "La distancia mas corta es: " << min_dist << endl;
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
    vector<Point> points_inside_limits_x = merge_vectors(points_inside_limits_left, points_inside_limits_right);


    //---------------------------------------------------------------------------------------

    //sort points by y-coordinate
    vector<Point> points_sorted_by_y = points;
    sort(points_sorted_by_y.begin(), points_sorted_by_y.end(), [](Point a, Point b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    //initialize left and right vectors
    vector<Point> left_y(points_sorted_by_y.begin(), points_sorted_by_y.begin() + mid);
    vector<Point> right_y(points_sorted_by_y.begin() + mid, points_sorted_by_y.end());

    //vector of points inside limits
    vector<Point> points_inside_limits_left_y = points_inside_limits(left_y, delta);
    vector<Point> points_inside_limits_right_y = points_inside_limits(right_y, delta);
    vector<Point> points_inside_limits_y = merge_vectors(points_inside_limits_left_y, points_inside_limits_right_y);

    //find common points inside limits
    vector<Point> common_points_inside_limits;
    for (int i = 0; i < points_inside_limits_x.size(); i++) {
        for (int j = 0; j < points_inside_limits_y.size(); j++) {
            if (points_inside_limits_x[i] == points_inside_limits_y[j]) {
                common_points_inside_limits.push_back(points_inside_limits_x[i]);
            }
        }
    }

    //---------------------------------------------------------------------------------------

    for (int i = 0; i < common_points_inside_limits.size(); i++) {
        for (int j = i + 1; j < i + 7; j++) {
            //break if j is major to size of vector
            if (j >= common_points_inside_limits.size()) {
                break;
            }
            else{
                min_dist = min(min_dist, distance(common_points_inside_limits[i], common_points_inside_limits[j]));
            }
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

    cout << "Implementacion busqueda geometrica\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el numero de puntos> ";
    cin >> n;
    //read points
    vector<Point> points(n);
    string m, k;
    for (int i = 0; i < n; i++) {
        cin >> m >> k;
        m.pop_back();
        points[i].x = stoi(m);
        points[i].y = stoi(k);
    }

    //find nearest pair of points
    nearest_pair_points(points);

    return 0;
}
