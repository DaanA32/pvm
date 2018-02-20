#include "linked_list.h"


/*
  Counts the number of elements in the list.

  The null pointer is written nullptr in C++.
*/
unsigned length(linked_list* lst)
{
    unsigned count = 0;
    while(lst != nullptr){
      lst = lst->next;
      ++count;
    }
    return count;
}

/*
  Finds the penultimate node in the list.
  The penultimate node is the node just before the last one.
  If there is no penultimate node (because the list is too short),
  return nullptr.
*/
linked_list* penultimate(linked_list* lst)
{
  if(lst == nullptr){
    return nullptr;
  }
  linked_list* first = lst;
  linked_list* previous = nullptr;
  while(lst->next != nullptr){
    previous = lst;
    lst = lst->next;
  }
  if(first == lst){
    return nullptr;
  }
  return previous;
}


linked_list* last(linked_list* lst)
{
    linked_list* first = lst;
    if(lst->next == nullptr){
      return lst;
    }
    while(lst->next != nullptr){
      lst = lst->next;
    }
    if(first == lst){
      return nullptr;
    }
    return lst;
}

/*
  Returns a pointer to the longest list.
  Keep it as efficient as possible: if you
  get a list of 1 long and one of 1 billion long,
  you do not want to spend time counting a billion elements.

  If both lists have equal length, return nullptr.
*/
linked_list* longest(linked_list* xs, linked_list* ys)
{
  if(xs == nullptr){
    return ys == nullptr ? nullptr : ys;
  }else if(ys == nullptr){
    return xs == nullptr ? nullptr : xs;
  }
  linked_list* x = xs;
  linked_list* y = ys;
  while( xs != nullptr && ys != nullptr){
    xs = xs->next;
    ys = ys->next;
  }
  if(xs == nullptr){
    return ys == nullptr ? nullptr : y;
  }else if(ys == nullptr){
    return xs == nullptr ? nullptr : x;
  }
}

/*
  Given a non-cyclic linked list, modifies
  it so as to make it cyclic by having
  the last node point to the first.
*/
void make_cyclic(linked_list* lst)
{
    linked_list* last_item = last(lst);
    last_item->next = lst;
}

/*
  Checks whether the linked list contains
  a cycle. You will not need a special
  data structure for this (i.e. no arrays,
  lists, sets, ... are necessary).
  If you need inspiration for how to do this,
  look up hares and turtoises.
*/
bool has_cycle(linked_list* lst)
{
  if(lst == nullptr || lst->next == nullptr){
    return false;
  }
  linked_list* tort = lst->next;
  if(lst == tort){
    return true;
  }else if(tort->next == nullptr){
    return false;
  }
  linked_list* hare = lst->next->next;
  if(lst == hare || tort == hare){
    return true;
  }
  while(tort != hare){
    if(hare->next == nullptr){
      return false;
    }
    hare = hare->next;
    if(hare->next == nullptr){
      return false;
    }
    hare = hare->next;
    tort = tort->next;
  }
  if(tort == hare && tort->next != nullptr){
    return true;
  }
}
