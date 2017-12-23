#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

class BinarySearch
{

public:
	BinarySearch();
	template <typename T> int search(const T arr[], int first, int last, const T& target);

};

#endif