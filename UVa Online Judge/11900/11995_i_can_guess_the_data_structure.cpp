#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> t_queue;
priority_queue<int> t_p_queue;
stack<int> t_stack;

void clear()
{
  queue<int> empty_q;
  priority_queue<int> empty_pq;
  stack<int> empty_s;
  swap(t_queue, empty_q);
  swap(t_p_queue, empty_pq);
  swap(t_stack, empty_s);
}

int main ()
{
    int count, command, element;
    bool is_stack, is_queue, is_p_queue, error = false;
    string result = "something";

    while (cin >> count) {
      cin.ignore();
      is_stack = is_queue = is_p_queue = true;
      while (count--) {
        cin >> command >> element;
        if (!error) {
          if (command == 1) {
            t_queue.push(element);
            t_p_queue.push(element);
            t_stack.push(element);
          } else {
            if (!t_queue.empty() && !t_p_queue.empty() && !t_stack.empty()) {
              if (is_queue)
                is_queue = (t_queue.front() == element) ? true : false;
              if (is_p_queue)
                is_p_queue = (t_p_queue.top() == element) ? true : false;
              if (is_stack)
                is_stack = (t_stack.top() == element) ? true : false;
              t_queue.pop(); t_p_queue.pop(); t_stack.pop();
            } else {
              is_stack = is_queue = is_p_queue = false;
              error = true;
            }
          }
        }
      }

      if ((is_queue && is_p_queue) || (is_p_queue && is_stack) || (is_stack && is_queue))
        result = "not sure";
      else if (!(is_queue || is_p_queue || is_stack))
        result = "impossible";
      else if (is_queue)
        result = "queue";
      else if (is_p_queue)
        result = "priority queue";
      else if (is_stack)
        result = "stack";

      cout << result << endl;
      clear();
    }
}
