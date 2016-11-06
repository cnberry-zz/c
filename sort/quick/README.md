Quick sort O(nlog(n))

This quicksort is a modification of the algorithm found in
"Data Structures & Algorithm Analysis in C++". Rather than
use the median3 and place the pivot in "right-1", here I place
the pivot in "right". This has the benifits:

	1) pivot method can be replaced with pivot = data[right]
	2) does not require sperate sort for degenerate cases

These reasons make it much easier to code correctly in an interview -
you can start with a simple pivot = data[right] implementation 
and when asked about performance on ordered or reverse ordered
arrays (both O(n^2)) you can add in the median3
method for lengths > 3 to get O(nlog(n)) without changing the core
partitioning implementation.
