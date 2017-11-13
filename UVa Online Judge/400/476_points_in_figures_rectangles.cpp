#include <iostream>
#include <vector>
using namespace std;

typedef pair<double,double> point;

struct figure
{
  int id;
  point p1;
  point p2;
  figure(int i, point pp1, point pp2):
    id(i), p1(pp1), p2(pp2){};
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

int main ()
{
  char type;
  int last_id = 0;
  vector<figure> figures;
  double x1, x2, y1, y2;

  while (cin >> type && type != '*')
  {
    cin >> x1 >> y1 >> x2 >> y2, cin.ignore();
    figures.push_back(figure(++last_id, point(x1,y1), point(x2,y2)));
  }

  double point_x, point_y;
  bool is_contained;
  last_id = 0;
  while(cin >> point_x >> point_y && point_x != 9999.9 && point_y != 9999.9) {
    cin.ignore();
    is_contained = false;
    last_id++;
    for (int i = 0; i < figures.size(); i++)
      is_contained |= point_in_rectangle(last_id, point(point_x, point_y), figures[i]);

    if (!is_contained)
      cout << "Point " << last_id << " is not contained in any figure" << endl;
  }

  return 0;
}
