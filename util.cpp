#include "util.h"
#include <vector>
#include <string>
#include <queue>
#include <functional>
using namespace sol1506;
using namespace std;

/* C++ notes
   - queue.front() won't remove the item
     from the queue; you need to call
     the queue.pop() to remove the item
     from the queue
*/
vector<Node *> LevelOrder::toVec(Node *tree)
{
    vector<Node *> result;
    if (tree == nullptr)
        return result;
    queue<Node *> q;
    q.push(tree);

    /*
      - in the beginning of each iteration,
        the queue will have nodes from
        a certain level
      - at the end of each iteration, the
        queue will have nodes from the next
        level
    */
    while (!q.empty())
    {
        /* visiting the node */
        auto node = q.front();
        result.push_back(node);
        q.pop();
        for (auto c : node->children)
            q.push(c);
    }

    return result;
}
string LevelOrder::toStr(Node *tree)
{

    return "";
}

int LevelOrder::height(Node *tree)
{

    if (tree == nullptr)
        return 0;

    function<int(Node *, int)> visit = [&visit](Node *node, int parentLevel)
    {
        int maxLevel = parentLevel + 1;
        for (auto c : node->children)
        {
            auto level = visit(c, parentLevel + 1);
            if (level > maxLevel)
                maxLevel = level;
        }
        return maxLevel;
    };
    /* root has not parent hence the parent level is 0 */
    return visit(tree, 0);
}