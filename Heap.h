/* 
 * Describes the basic operations of a binary heap
 * @author Duncan
 * @param <E> the heap element type
 * @since 99-99-9999
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <vector>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

/**
 * This class reports Heap exceptions.
 */
class HeapException
{
private:
   /**
    * Reason for the exception
	*/
   string message;	
public:
   /**
    * Constructs a HeapException
    * @param aMessage why the exception occurred
	*/
   HeapException(const string& aMessage)
   {
      message = aMessage;
   }   
   /**
    * Gives a reason for this exception
	* @return why the this exception occurred
	*/
   string what() const
   {
      return message;
   }
};

template <typename E>
class Heap
{
private:
   /**
    * A complete tree stored in a vector representing this 
    * binary heap
    */
   vector<E> tree;
   /**
    * Swaps a parent and child elements of this heap at the specified indices
    * @param place an index of the child element on this heap
    * @param parent an index of the parent element on this heap
    */   
   void swap(int place, int parent);
   /**
    * Rebuilds the heap to ensure that the heap property of the tree is preserved.
    * @param root the root index of the subtree to be rebuilt
    * @param eSize the size of this tree
    */   
   void reheapify(int root, int eSize);   
public:
   /**
      Constructs an empty heap;
   */
   Heap<E>();

   /**
      destructor - returns the heap memory to the system;
   */
   ~Heap<E>();

   /**
      Determine whether the heap is empty.
      @return true if the heap is empty;
      otherwise, it returns false if the tree contains at least one item.
   */
   bool isEmpty() const;

   /**
      Inserts an item into the heap.
      @param item the value to be inserted.
      @return none
   */
   void insert(E item);

   /**
      An exception is generated if this method is invoked
      by an empty heap. The maximum/minimum value is removed
      from the heap if the heap is not empty and its effective
      size is reduced by 1.
      @return the maximum (in the case of a maxheap) or the
      minimum (in the case of a minheap) on the heap.
   */
   E remove() throw (HeapException);

   /**
      An exception is generated if this method is invoked
      by an empty heap
      @return the maximum (in the case of a maxheap) or the
      minimum (in the case of a minheap) on the heap.
   */
   const E& peek() const throw (HeapException);

      
   /**
      @return the size of the heap; the effective size of the 
      heap.
   */
   int size() const;
   
};
//HEAP_H
#endif


