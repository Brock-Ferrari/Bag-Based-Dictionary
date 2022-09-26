#pragma once

#include <iostream>
#include "bagADT.h"
#include "kvpair.h"
#include <vector>
using namespace std; // Giving me lots of trouble to remove. Going to leave in for now.

template <typename E>///////////////////////////
class ABag : public Bag <E>
{
public:
	ABag() { }
	ABag(int s) { /*pile.max_size(s);*/ } // Returns an error...
	~ABag() { }

	// Checks to see if bag is at capacity and then adds object to vector
	bool addItem(const E& item)
	{
		if (pile.size() < bagCapacity())
		{
			pile.push_back(item);	// vector uses push_back() 
			return true;
		}
		else
			return false;
	}

	// Loops through vector to find a matching object
	// If found, sets item equal to that object and then shifts data to replace the removed vector position
	// Deletes last vector object because memory is still allocated in that position
	bool remove(E& item)
	{
		for (int i = 0; i < pile.size(); i++)
		{
			if (pile[i] == item)
			{
				item = pile[i];
				for (int j = i; j < (pile.size() - 1); j++)
				{
					pile[j] = pile[j + 1];
				}
				pile.pop_back();
				return true;
			}
		}
		return false;
	}

	// Sets the most recently added item to returnValue
	// Uses pop_back() to delete object on top
	bool removeTop(E& returnValue)
	{
		if (pile.size() > 0)
		{
			returnValue = pile[pile.size() - 1];
			pile.pop_back(); // deletes object on top
			return true;
		}
		else
			return false;
	}

	// Finds returnValue in vector and returns true if found
	bool find(E& returnValue) const
	{
		for (int i = 0; i < pile.size(); i++)
		{
			if (pile[i] == returnValue)
			{
				returnValue = pile[i];
				return true;
			}
		}
		return false;
	}

	// Checks to see if the bag is empty and returns false if it is, true otherwise.
	bool inspectTop(E& item) const
	{
		if (pile.size() > 0)
		{
			item = pile[pile.size() - 1];
			return true;
		}
		else
			return false;
	}

	// Simply clears the vector
	void emptyBag()
	{
		pile.clear();
		return;
	}

	// Overloads the operator +=. Does the same as addItem. Should I just call addItem()
	bool operator+=(const E& addend)
	{
		if (pile.size() < bagCapacity())
		{
			pile.push_back(addend);
			return true;
		}
		else
			return false;
	}

	// Simply returns the size of the vector
	int size() const
	{
		return pile.size();
	}

	// Returns bag capacity. Should not change.
	int bagCapacity() const
	{
		return 10;
	}
private:
	vector<E> pile; // Vector for KVpair objects
};
