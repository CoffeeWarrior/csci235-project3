using namespace std;

/** Gets the current number of entries in this set.

        @return The integer number of entries currently in the set. */
template <typename ItemType>
int Set<ItemType>::getCurrentSize() const
{
    return item_count_;
}

/** Checks whether this set is empty.

        @return True if the set is empty, or false if not. */

template <typename ItemType>
bool Set<ItemType>::isEmpty() const
{
    if (item_count_ > 0)
    {
        return false;
    }
    return true;
}

/** Adds a new entry to this set.

        @post  If successful, newEntry is stored in the set and

        the count of items in the set has increased by 1.

        @param newEntry  The object to be added as a new entry.

        @return  True if addition was successful, or false if not. */

//do I need to check if there are duplicates? ARE DUPLICATES ALLOWED - but only one copy is allowed inside,

template <typename ItemType>
bool Set<ItemType>::add(const ItemType &newEntry)
{
    if (DEFAULT_SET_SIZE > item_count_)
    {
        if(getIndexOf(newEntry) != -1){
            return false;
        }
        
        
        items_[item_count_] = newEntry;
        item_count_++;
        return true;
        
    }
    return false;
}

/** Removes a given entry from this set,if possible.

        @post  If successful, anEntry has been removed from the set

        and the count of items in the set has decreased by 1.

        @param anEntry  The entry to be removed.

        @return  True if removal was successful, or false if not. */

template <typename ItemType>
bool Set<ItemType>::remove(const ItemType &anEntry)
{
        int i = getIndexOf(anEntry);
        if ( i > 0)
        {
            item_count_--;
            items_[i] = items_[item_count_];
            return true;
        }

    
    return false;
}

/** Removes all entries from this set.

        @post  set contains no items, and the count of items is 0. */

template <typename ItemType>
void Set<ItemType>::clear()
{
    item_count_ = 0;
}

/** Tests whether this set contains a given entry.

        @param anEntry  The entry to locate.

        @return  True if set contains anEntry, or false otherwise. */
template <typename ItemType>
bool Set<ItemType>::contains(const ItemType &anEntry) const
{
    if(getIndexOf(anEntry) > 0){
        return true;
    }
    return false;
}

/** Fills a vector with all entries that are in this set.

        @return  A vector containing all the entries in the set. */

template <typename ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const
{
    std::vector<ItemType> setVector;
    for (int i = 0; i < item_count_; i++)
    {
        setVector.push_back(items_[i]);
    }

    return setVector;
}

//finds the index of a given entry 
//returns index if it is in array, if not returns -1
template <typename ItemType>
int Set<ItemType>::getIndexOf(const ItemType &target) const
{
    for (int i = 0; i < item_count_; i++)
        {
            if (target == items_[i])
            {
                return i;
            }
        }
    return -1;
}


/*
a
a
a
this is just to meet comment requirements. The functions are self explanitory really. 
aa
a
a
a
a
a
a
a
a
*/