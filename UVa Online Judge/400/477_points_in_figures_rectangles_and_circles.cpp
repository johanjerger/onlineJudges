#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef pair<double,double> point;

struct figure
{
  int id;
  char type;
  point p1;
  point p2;
  double radius;
  figure(int i, char t, point pp1, point pp2):
    id(i), type(t), p1(pp1), p2(pp2){};
  figure(int i, char t, point pp1, double r):
    id(i), type(t), p1(pp1), radius(r){};
};

bool print(int id_p, int id_f)
{
  cout << "Point " << id_p << " is contained in figure " << id_f << endl;
  return true;
}

bool point_in_rectangle(int id, point p, figure r)
{
  if(((p.first > r.p1.first) && (p.first < r.p2.first)) &&
     ((p.second < r.p1.second) && (p.second > r.p2.second)))
    return print(id, r.id);
  else return false;
}

bool point_in_circle(int id, point p, figure c)
{
  double distance = sqrt(pow(p.first - c.p1.first, 2) + pow(p.second - c.p1.second, 2));
  if(distance < c.radius) return print(id, c.id);
  else return false;
}

int main ()
{
  char type;
  int last_id = 0;
  vector<figure> figures;
  double x1, x2, y1, y2, r;

  while (cin >> type && type != '*')
  {
    if (type == 'r') {
      cin >> x1 >> y1 >> x2 >> y2, cin.ignore();
      figures.push_back(figure(++last_id, type, point(x1,y1), point(x2,y2)));
    } else if (type == 'c') {
      cin >> x1 >> y1 >> r, cin.ignore();
      figures.push_back(figure(++last_id, type, point(x1,y1), r));
    }
  }

  double point_x, point_y;
  bool is_contained;
  last_id = 0;
  while(cin >> point_x >> point_y && point_x != 9999.9 && point_y != 9999.9) {
    cin.ignore();
    is_contained = false;
    last_id++;
    for (int i = 0; i < figures.size(); i++) {
      if (figures[i].type == 'r')
        is_contained |= point_in_rectangle(last_id, point(point_x, point_y), figures[i]);
      else if (figures[i].type == 'c')
        is_contained |= point_in_circle(last_id, point(point_x, point_y), figures[i]);
    }

    if (!is_contained)
      cout << "Point " << last_id << " is not contained in any figure" << endl;
  }

  return 0;
}
