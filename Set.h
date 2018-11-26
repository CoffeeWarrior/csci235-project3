#ifndef _SET_H_
#define _SET_H_
#include <vector>
#include "SetInterface.h"

//example here: https://stackoverflow.com/questions/32898976/how-to-inherit-from-template-class-c?lq=1
//the
template <typename ItemType>
class Set : public SetInterface<ItemType>
{
  public:
    /** Gets the current number of entries in this set.

        @return The integer number of entries currently in the set. */

    int getCurrentSize() const override;

    /** Checks whether this set is empty.

        @return True if the set is empty, or false if not. */

    bool isEmpty() const override;

    /** Adds a new entry to this set.

        @post  If successful, newEntry is stored in the set and

        the count of items in the set has increased by 1.

        @param newEntry  The object to be added as a new entry.

        @return  True if addition was successful, or false if not. */

    bool add(const ItemType &newEntry) override;

    /** Removes a given entry from this set,if possible.

        @post  If successful, anEntry has been removed from the set

        and the count of items in the set has decreased by 1.

        @param anEntry  The entry to be removed.

        @return  True if removal was successful, or false if not. */

    bool remove(const ItemType &anEntry) override;

    /** Removes all entries from this set.

        @post  set contains no items, and the count of items is 0. */

    void clear() override;

    /** Tests whether this set contains a given entry.

        @param anEntry  The entry to locate.

        @return  True if set contains anEntry, or false otherwise. */

    bool contains(const ItemType &anEntry) const override;

    /** Fills a vector with all entries that are in this set.

        @return  A vector containing all the entries in the set. */

    std::vector<ItemType> toVector() const override;

  private:
    static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small

    ItemType items_[DEFAULT_SET_SIZE]; // array of set items

    int item_count_ = 0; // current count of set items

    int max_items_ = DEFAULT_SET_SIZE - 1; // max capacity of the set

    // post: Either returns the index of target in the array items_

    // or -1 if the array does not contain the target

    int getIndexOf(const ItemType &target) const;
};

#include "Set.cpp"
#endif
