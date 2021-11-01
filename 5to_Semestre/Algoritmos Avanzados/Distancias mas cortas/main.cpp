#include <iostream>

using namespace std;

//function to calculate direction of three points
int direction(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int val = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}

//function to check if points are on segment
bool onSegment(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (x2 <= max(x1, x3) && x2 >= min(x1, x3) && y2 <= max(y1, y3) && y2 >= min(y1, y3))
        return true;
    return false;
}


bool segmentIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int d1, d2, d3, d4;
    d1 = direction(x3, y3, x4, y4, x1, y1);
    d2 = direction(x3, y3, x4, y4, x2, y2);
    d3 = direction(x1, y1, x2, y2, x3, y3);
    d4 = direction(x1, y1, x2, y2, x4, y4);

    if (d1 != d2 && d3 != d4)
        return true;

    if (d1 == 0 && onSegment(x3, y3, x4, y4, x1, y1))
        return true;

    if (d2 == 0 && onSegment(x3, y3, x4, y4, x2, y2))
        return true;

    if (d3 == 0 && onSegment(x1, y1, x2, y2, x3, y3))
        return true;

    if (d4 == 0 && onSegment(x1, y1, x2, y2, x4, y4))
        return true;

    return false;
}


int main(){
    
    //read n coordinates and store in array
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    //check if there is intersection
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(segmentIntersection(x[i], y[i], x[j], y[j], x[(i+1)%n], y[(i+1)%n], x[(j+1)%n], y[(j+1)%n])){
                cout << true << endl;
                return 0;
            }
            else{
                cout << false << endl;
            }
        }
    }
    
    return 0;
}

