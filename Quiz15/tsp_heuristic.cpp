#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
    int index;
    float x;
    float y;
}point;

float getDistance(point &a, point &b){
    float dist;
    dist = sqrt( pow((a.x-b.x),2) + pow((a.y-b.y),2));
    return dist;
}
int main()
{
    fstream file;
    file.open("nn.txt");
    int num; //33708
    vector<point> points(num + 1);
    file >> num;

    while (file.peek() != EOF)
    {
        point p;
        float x, y;
        int index;
        file >> index >> x >> y;
        p.index = index;
        p.x = x;
        p.y = y;
        points[index] = p;
    }
    vector<int> check (num + 1, 0);
    int visited = 0;
    check[1] = 1;
    visited++;
    int cur = 1;
    float distance = 0;
    while (visited < num){
        float min = FLT_MAX;
        int next = 1;
        for(int i = 2; i <= num; i++){
            if(check[i] != 0) continue;
            if(getDistance(points[cur], points[i]) < min){
                min = getDistance(points[cur], points[i]);                
                next = i;
            }
        }
        visited++;
        if(visited == num){
            distance += min;
            break;
        }
        cur = next;
        check[next] = next;
        distance += min;
    }
    distance += getDistance(points[cur], points[1]);
    cout << distance << endl;
    return 0;
}