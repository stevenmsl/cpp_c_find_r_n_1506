#include "solution.h"

#include <functional>
#include <unordered_map>
#include <cinttypes>
using namespace sol1506;
using namespace std;

/* takeaways - constant space complexity with a linear time algorithm
   - that means you can't create a map to record who the node's parent
     is as the size will grow as the number of the nodes grow
   - you can only scan the list once
   - so you need to have just one int variable to record which nodes
     have been visited with XOR operations
   - all nodes will be visited exactly twice except the root
*/

/* takeaways - XOR
   - let say we have nodes 1,2,3,4, so you need 3 bits to represent them
     000. Think of this as a panel with 3 switches and are labelled from
     right to left as "1", "2", "3" individually. Initially they are
     all off
   - let's visit all 4 nodes at any random order.
   - let say the order is 4->1->2->3
   - since we only have 3 switches, it's the same as
     4->1->2->(1+2). Times swithces will be toggled:
     4 : 1 time
     2 : 2 times
     1 : 2 times
     so in the end switch will remain on. this is
     just an observation and is unrelated to why
     it works.
   - now let's visit the nodes the second time
     at any random order again. Let's pick one
     1->3->2->4, which is the same as 1->(1+2)->2->4
     Times switches will be toggled include the
     first round:
     4 : 2 times
     2 : 4 times
     1 : 4 times
   - each switch has been toggled even number of times
     so it must be off in the end after two rounds!

   - let say if we don't visit 3 at the second run
     then the times switches toggled in total will
     be like this:
     4 : 2 times
     2 : 3 times
     1 : 3 times
     - 1 and 2 is on in the end, so we know it's 3
       that is the leftover which is the root
     - try other cases and it will become clear

*/

/* takeaways - XOR math
   - XOR means toggling it on/off
     - 0^1 = 1, 1^1 = 0
   - let's start with a very simple tree
        1
       / \
      2   3
   - let say the input vec is {Node(3), Node(2), Node(1)}
   - we need 2 bits to represent the numbers 00
   - the order we apply the XOR will be like the following:
     0 ^ 3 = 3
       - visit 3
       - 00->11
       - (3=1+2, turn on both switches)
     3 ^ 2 = 1 ( 3=1+2, 3^2 means remove 2)
       - visit 2
       - 11->01
     1 ^ 1 = 0 ( 1=1 so remove 1 - back to square one)
       - visit 1
       - 01->00
       - every node has been visited
     0 ^ 2 = 2 (turn 2 on)
       - visit 2
       - 00->10
     2 ^ 3 = 1 ( 3=1+2 so add 1 and remove 2)
       - 10->01 (1 is the root as it has not been visited twice)

*/

Node *Solution::findRoot(vector<Node *> &tree)
{
  int root = 0;
  for (auto node : tree)
  {
    root ^= node->val;
    for (auto child : node->children)
    {
      root ^= child->val;
    }
  }

  for (auto node : tree)
    if (node->val == root)
      return node;

  return nullptr;
}