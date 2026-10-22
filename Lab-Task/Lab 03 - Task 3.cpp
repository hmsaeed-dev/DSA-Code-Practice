/*Measure the work. Complexity is a claim about how the work grows, so test it. Add a counter to
every sorting function and count the comparisons (every time two array elements are compared
in an if or while). For n = 10, 100 and 1000, fill the array in reverse order (n, n − 1, …, 1),
sort it with each algorithm, and record the counts in a table like this one:
n Bubble Selection Insertion Quick Merge
10
100
1000
Then sort the already sorted array 1, 2, 3, … n with insertionSort for the same three values of n and
record its comparisons. Answer in two or three lines each:
UNIVERSITY OF ENGINEERING AND TECHNOLOGY, TAXILA
DEPARTMENT OF COMPUTER SCIENCE
http://web.uettaxila.edu.pk
Lab Manual: Data Structures and Algorithms
(a) When n becomes 10 times bigger, what happens to the counts of Bubble, Selection and Insertion?
What happens to the count of Merge Sort?
(b) Which counts match O(n²) and which match O(n log n)?
(c) Quick Sort uses the same number of comparisons as Bubble Sort here. Why? (Hint: which element
is the pivot, and what does the array look like?)
(d) Insertion Sort on the already sorted array needs only about n comparisons. Which case is this, and
what is its complexity?
Challenge (optional). Change bubbleSort so that it sorts in descending order by changing only one
symbol. Which symbol is it?*/
