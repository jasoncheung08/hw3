#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m(m), comp(c) {
    if (m < 2) {
      m = 2;
    }
  };

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item) {
    data.push_back(item);
    siftUp(data.size() - 1);
  };

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const {
    if(empty()) {
      throw std::underflow_error("Heap is empty");
    }
    return data[0];
  };

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop() {
    if(empty()) {
      throw std::underflow_error("Heap is empty");
    }
    data[0] = data.back();
    data.pop_back();
    if(!empty()) {
      siftDown(0);
    }
  };

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const {
    return data.empty();
  };

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const {
    return data.size();
  };

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator comp;
  void siftUp(size_t i) {
    while(i > 0) {
      size_t parent = (i - 1) / m;
      if (comp(data[i], data[parent])) {
        std::swap(data[i], data[parent]);
        i = parent;
      }
      else {
        break;
      }
    }
  }

  void siftDown(size_t i) {
    size_t n = data.size();
    while (true) {
      size_t best = i;

      for(size_t k = 1; k <= static_cast<size_t>(m); k++) {
        size_t child = m * i + k;
        if (child < n && comp(data[child], data[best])) {
          best = child;
        }
      }
      if (best != i) {
        std::swap(data[i], data[best]);
        i = best;
      }
      else {
        break;
      }
    }
  }

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
//template <typename T, typename PComparator>
//T const & Heap<T,PComparator>::top() const
//{
//  // Here we use exceptions to handle the case of trying
//  // to access the top element of an empty heap
//  if(empty()){
//    // ================================
//    // throw the appropriate exception
//    // ================================


//  }
//  // If we get here we know the heap has at least 1 item
//  // Add code to return the top element



//}


//// We will start pop() for you to handle the case of 
//// calling top on an empty heap
//template <typename T, typename PComparator>
//void Heap<T,PComparator>::pop()
//{
//  if(empty()){
//    // ================================
//    // throw the appropriate exception
//    // ================================


//  }



//}



#endif

