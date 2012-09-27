#include <unordered_map>

#include "../../ex1/src/graph.h"

namespace inf5016 {

class VebTree {
 public:
  VebTree();

  void push(const Edge& e);

  void pop();

  void update(const int vert, const int new_cost);

  inline Edge& top();
  const Edge& top() const;

  int size();
  bool empty();
  void clean();

 private:
  std::unordered_map<Edge, bool> base_;
};

}
