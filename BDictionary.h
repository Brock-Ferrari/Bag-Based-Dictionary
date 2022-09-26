#pragma once

#include "dictionaryADT.h"
#include "kvpair.h"
#include "ABag.h"

template <typename Key, typename E>///////////////////////////
class BDictionary : public Dictionary <Key, E>
{
public:
	BDictionary()
	{
		dict = std::make_unique<ABag<KVpair<Key, E>>>; // default constructor, does not need value
	}
	BDictionary(int maxsize) 
	{ 
		dict = std::make_unique<ABag<KVpair<Key, E>>>(maxsize); // must incorporate maxsize in this constructor
	}
	~BDictionary() { }

	// Simply calls emptyBag()
	void clear()
	{
		dict->emptyBag();
		return;				// void return
	}

	// Creates temporary KVpair with key and value passed in as arguments. Returns true or false if insert is successful
	bool insert(const Key& k, const E& e)
	{
		KVpair<Key, E> temp(k, e);
		return dict->addItem(temp);
	}

	// Passes KVpair into remove in bag function. Sets rtnVal equal to the value removed and returns true. Returns false if remove is unsuccsesful 
	bool remove(const Key& k, E& rtnVal)
	{
		KVpair<Key, E> temp(k, rtnVal);
		if (dict->remove(temp))
		{
			rtnVal = temp.value();
			return true;
		}
		return false;
	}

	// Checks if dictionary is empty. Passes a blank KVpair into removeTop and sets returnValue equal to the object removed.
	bool removeAny(E& returnValue)
	{
		if (dict->size() == 0)
			return false;

		KVpair<Key, E> temp;
		dict->removeTop(temp);
		returnValue = temp.value();
		return true;
	}

	// Sets returnValue equal to the value of the KVpair passed into the method. Calls find() in bag
	bool find(const Key& k, E& returnValue) const
	{
		KVpair<Key, E> temp(k, returnValue);
		if (dict->find(temp))
		{
			returnValue = temp.value();
			return true;
		}
		return false;
	}

	// Simply calls size in bag
	int size()
	{
		return dict->size();
	}
private:
	std::unique_ptr<ABag<KVpair<Key, E>>> dict;
};