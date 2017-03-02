
/**
 * Implementation for the Heap<E> class
 * @author Duncan, Bryan Stamey
 * @since 02-16-2017
 * Course: CSC3102.01
 * Programming Project #: 1
 * Instructor: Dr. Duncan
 * @see Heap.h
 */

#include "Heap.h"
#include <algorithm>

using namespace std;

template <typename E>
Heap<E>::Heap()
{
   // compiler-generated code .. no need to implement this
}

template <typename E>
Heap<E>::~Heap()
{
   while(tree.size() > 0)
      tree.pop_back();
}


template <typename E>
bool Heap<E>::isEmpty() const
{
    return tree.empty();                //checks for empty
}


template<typename E>
void Heap<E>::insert(E item)
{
    tree.push_back(item);               //push new item onto end of vector
    int place = Heap<E>::size() - 1;    //place = heap size
    int parent = (place - 1) / 2;       //index of parent
    while (parent >= 0 && tree[place] > tree[parent]) { //parent >= root & node > parent node
        Heap<E>::swap((place), parent);   //switch node and parent
        place = parent;                 //reassign place index to parent index
        parent = (place - 1) / 2;       //calculate new parent
    }
}


template<typename E>
E Heap<E>::remove() throw (HeapException)
{
    if (Heap<E>::isEmpty() == true) {       //throw exception for empty heap
        throw "err: heap is empty";
    }
    else {
        E root = tree[0];                               //save root
        tree[0] = tree[Heap<E>::size() - 1];            //overwrite root with last
        tree.pop_back();                                //delete last element
        Heap<E>::reheapify(0, Heap<E>::size());         //reheapify
        return root;                                    //return original root
    }
}


template<typename E>
const E& Heap<E>::peek() const throw (HeapException)
{
    if (Heap<E>::isEmpty() == true) {       //throw exception for empty heap
        throw "err: heap is empty";
    }
    else {
        return tree[0];         //return root
    }
}


template<typename E>
int Heap<E>::size()const
{
    return tree.size();
}


template<typename E>
void Heap<E>::swap(int place, int parent)
{
    iter_swap(tree.begin() + place, tree.begin() + parent);//swap child & parent
}


template<typename E>
void Heap<E>::reheapify(int root, int eSize)
{
    if (2 * root + 1 <= (eSize - 1) || 2 * root + 2 <= (eSize - 1)) { //root not leaf (no children)  CHECK FROM HERE
        int child = 2 * root + 1;               //left child
        if (child + 1 < eSize) {               //if right child exists
            if (tree[child + 1] > tree[child]) {    //child + 1 > child
                child = child + 1;              // child + 1
            }
        }
        if (tree[root] < tree[child]) {         // if root < child
            Heap<E>::swap(root, child);         // swap root and child
            Heap<E>::reheapify(child, eSize);   //reheapify new tree
        }
    }
}