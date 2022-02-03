#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1506;

/*
 Input: root = [1,null,3,2,4,null,5,6]
 Output: [1,null,3,2,4,null,5,6]
*/

Node *testFixture1()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->children.push_back(new Node(3));
  tree->children.push_back(new Node(2));
  tree->children.push_back(new Node(4));

  tree->children[0]->children.push_back(new Node(5));
  tree->children[0]->children.push_back(new Node(6));

  return tree;
}

/*
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
*/

Node *testFixture2()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->children.push_back(new Node(2));
  tree->children.push_back(new Node(3));
  tree->children.push_back(new Node(4));
  tree->children.push_back(new Node(5));

  /* level 3 */
  tree->children[1]->children.push_back(new Node(6));
  tree->children[1]->children.push_back(new Node(7));

  tree->children[2]->children.push_back(new Node(8));

  tree->children[3]->children.push_back(new Node(9));
  tree->children[3]->children.push_back(new Node(10));

  /* level 4 */
  tree->children[1]->children[1]->children.push_back(new Node(11));
  tree->children[2]->children[0]->children.push_back(new Node(12));
  tree->children[3]->children[0]->children.push_back(new Node(13));

  /* level 5 */
  tree->children[1]->children[1]->children[0]->children.push_back(new Node(14));

  return tree;
}

void test1()
{
  auto fixture = testFixture1();
  auto input = LevelOrder::toVec(fixture);

  /* shuffle the input */
  swap(input[0], input[1]);
  swap(input[2], input[3]);

  cout << "Test 1 - expect to see Node(1) as the root" << endl;
  Solution sol;
  auto root = sol.findRoot(input);
  cout << "result: " << root->val << endl;
}

void test2()
{
  auto fixture = testFixture2();
  auto input = LevelOrder::toVec(fixture);

  /* shuffle the input */
  swap(input[0], input[1]);
  swap(input[2], input[3]);

  cout << "Test 2 - expect to see Node(1) as the root" << endl;
  Solution sol;
  auto root = sol.findRoot(input);
  cout << "result: " << root->val << endl;
}

void testLevelOrderHeight()
{
  auto fixture = testFixture2();
  cout << " Test Level Order Height - expect to see 5" << endl;
  cout << "tree height: " << LevelOrder::height(fixture) << endl;
}

void tesLevelOrderToVec()
{
  auto fixture = testFixture1();
  cout << " Test Level Order to Vec" << endl;
  cout << "result: use debugger to verify result" << endl;

  auto tree = LevelOrder::toVec(fixture);
}

void testXOR()
{
  int root = 0;
  int node = 1;

  root ^= node;

  root ^= 2;
  root ^= 3;
  root ^= 2;
  root ^= 3;
}

main()
{
  test1();
  test2();
  //  testLevelOrderHeight();
  //  tesLevelOrderToVec();
  // testXOR();

  return 0;
}