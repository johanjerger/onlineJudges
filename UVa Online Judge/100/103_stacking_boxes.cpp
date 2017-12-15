#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct box
{
  int id;
  vector<int> dims;
};

bool is_nest_in(box box1, box box2)
{
  int size = box1.dims.size();
  do {
    bool is_nest = true;
    for (int i = 0; i < size; ++i) is_nest &= (box1.dims[i] < box2.dims[i]);
    if (is_nest) return true;
  } while ( next_permutation( box1.dims.begin(), box1.dims.end() ) );
  return false;
}

int lis( vector<box> boxes )
{
   int maximum = 0;
   int size = boxes.size();
   vector<int> lis(size, 1);

   for ( int i = 1; i < size; i++ )
      for ( int j = 0; j < i; j++ )
         if ( !is_nest_in(boxes[i], boxes[j]) && lis[i] < lis[j] + 1 ) {
              lis[i] = lis[j] + 1;
         }


   for ( int i = 0; i < size; i++ ) maximum = max(maximum, lis[i]);

   return maximum;
}

void print_path (int x)
{
    if ( x == parent [x] )
        return ;
    print_path (parent [x]);
    v.push_back (a [parent [x]].id);
}

int main ()
{
  vector<box> boxes;
  box input_box;
  int boxs_number, boxs_dimension, dimension_size, last_box = 1;

  while (cin >> boxs_number >> boxs_dimension) {
    while (boxs_number--) {
      input_box.id = last_box++;
      for (int i = 0; i < boxs_dimension; ++i) {
        cin >> dimension_size;
        input_box.dims.push_back(dimension_size);
      }
      sort(input_box.dims.begin(), input_box.dims.end());
      boxes.push_back(input_box);
      input_box.dims.clear();
    }
    sort(boxes.begin(), boxes.end(), is_nest_in);
    cout << lis(boxes) << endl;
    boxes.clear();
    last_box = 0;
  }
}
