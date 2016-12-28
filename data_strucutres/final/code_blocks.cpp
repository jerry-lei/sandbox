void bt_recursion(vector path, vector<vector> solution){
  path.push_back(point);
  if(finished)
    solutions.push_back(path)
  bt(up); bt(down); bt(left); bt(right);
}

//2-d array
int** ary = new int*[rowCT];
for(int c1=0;c1<rowct;c1++)
  ary[c1] = new int[colCt];
//delete
for(int c1=0;c1<rowct;c1++)
  delete [] ary[c1];
delete [] ary;


template <class T>
class priority_queue {
private:
  std::vector<T> m_heap;
public:
  priority_queue( std::vector<T> const& values )
  const T& top() const
  {
    assert( !m_heap.empty() );
    return m_heap[0];
  }

  void push( const T& entry )

  void pop() {}

  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }
};


void driving(std::vector<std::string> &path, const Car &car, int max_steps,
  std::vector<Car> previous = std::vector<Car>()) {
  // base case, solution!
  if (path.size() > 0 && car == Car(0,0,"north")) {
    std::cout << "closed loop: ";
    for (int i = 0; i < path.size(); i++) {
    std::cout << " " << path[i];
    }
    std::cout << std::endl;
    return;
  }
  // base case, maximum recursion depth
  if (path.size() == max_steps) { return; }
  // make sure we aren't overlapping previous car positions
  // note: we are allowing the path to cross though!
  for (int i = 0; i < previous.size(); i++) {
    if (car == previous[i]) return;
  }
  previous.push_back(car);
  // try to go straight
  path.push_back("straight");
  driving(path,go_straight(car),max_steps,previous);
  path.pop_back();
  // try to go left
  path.push_back("left");
  driving(path,turn_left(car),max_steps,previous);
  path.pop_back();
  // try to go right
  path.push_back("right");
  driving(path,turn_right(car),max_steps,previous);
  path.pop_back();
  previous.pop_back();
}
