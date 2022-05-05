#ifndef BSTSETH
#define BSTSETH

#include "TNode.h"
#include <vector>

class BSTSet
{
private:
    // must contain only one private field
    TNode* root;

public:
    // required constructors/destructor
    BSTSet();
    BSTSet(const std::vector<int>& input);
    ~BSTSet();

    // required methods
    bool isIn(int v);
    void add(int v);
    bool remove(int v);
    void rUnion(const TNode* n);
    void Union(const BSTSet& s);
    void rIntersection(const TNode* n, const BSTSet& s);
    void intersection(const BSTSet& s);
    void rDifference(const TNode* n, const BSTSet& s);
    void difference(const BSTSet& s);
    int rSize(const TNode* n, int size);
    int size();
    int rHeight(const TNode* n, int mh, int h);
    int height();
    void printNonRec(); // create and use class MyStack

    // provided recursive print method
    void printBSTSet();

    // Used for testing
    TNode* getRoot()
    {
        return root;
    }

private:
    // provided helper methods
    void printBSTSet(TNode* t);
};

#endif /* BSTSETH */
