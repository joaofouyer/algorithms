# 10 days of Statistics :bar_chart:

A small set of simple statistics problems.

## Day 0: Mean, Median and Mode

[In this](https://www.hackerrank.com/challenges/s10-basic-statistics/problem) challenge, we practice calculating the mean, median, and mode. 

Given an array, _X_, of _N_ integers, calculate and print the respective mean, median, and mode on separate lines. If your array contains more than one modal value, choose the numerically smallest one.

Note: Other than the modal value (which will always be an integer), your answers should be in decimal form, rounded to a scale of 1 decimal place (i.e., 12.3, 7.0 format).

**Constraints**

- 10 <= N <= 2500
- 0 < x _i_ <= 10^5, where x_i_ is the i(th) element of array X.


**Sample Input**

```
10
64630 11735 14216 99233 14470 4978 73429 38120 51135 67060
```

**Sample Output**

```
43900.6
44627.5
4978
```

## Day 0: Weighted Mean

[In this](https://www.hackerrank.com/challenges/s10-weighted-mean/problem) challenge, we practice calculating a weighted mean. 

Given an array, _X_, of _N_ integers and an array, _W_, representing the respective weights of _X_'s elements, calculate and print the weighted mean of _X_'s elements. Your answer should be rounded to a scale of 1 decimal place (i.e., 12.3 format).

**Constraints**

- 5 <= N <= 50
- 0 < x _i_ <= 100, where x_i_ is the i(th) element of array X.
- 0 < w _i_ <= 100, where w_i_ is the i(th) element of array W.


**Sample Input**

```
5
10 40 30 50 20
1 2 3 4 5
```

**Sample Output**

```
32.0
```

## Day 1: Quartiles
[In this](https://www.hackerrank.com/challenges/s10-quartiles/problem) challenge, we practice calculating quartiles. 

Given an array, X, n of  integers, calculate the respective first quartile (Q1), second quartile (Q2), and third quartile (Q3). It is guaranteed that Q1, Q2, Q3 and  are integers.

**Constraints**

- 5 <= N <= 50
- 0 < x _i_ <= 100, where x_i_ is the i(th) element of array X.


**Sample Input**

```
9
3 7 8 5 12 14 21 13 18
```

**Sample Output**

```
6
12
16
```

## Day 1: Interquartile Range
[In this](https://www.hackerrank.com/challenges/s10-interquartile-range/problem) challenge, we practice calculating the interquartile range.


The interquartile range of an array is the difference between its first (Q1) and third (Q3) quartiles (i.e., Q3 - Q1).

Given an array, X, of n integers and an array, F, representing the respective frequencies of X's elements, construct a data set, S, where each xi occurs at frequency fi. Then calculate and print 's interquartile range, rounded to a scale of 1 decimal place (i.e., 12.3 format).

> Tip: Be careful to not use integer division when averaging the middle two elements for a data set with an even number of elements, and be sure to not include the median in your upper and lower data sets.


**Sample Input**

```
6
6 12 8 10 20 16
5 4 3 2 1 5
```

**Sample Output**

```
9.0
```

## Day 1: Standard Deviation

[In this](https://www.hackerrank.com/challenges/s10-standard-deviation/problem) challenge, we practice calculating standard deviation. 

Given an array, X, of N integers, calculate and print the standard deviation. Your answer should be in decimal form, rounded to a scale of 1 decimal place (i.e., 12.3 format). An error margin of +- 0.1 will be tolerated for the standard deviation.

**Constraints**

- 5 <= N <= 100
- 0 < x _i_ <= 10^5, where x_i_ is the i(th) element of array X.


**Sample Input**

```
5
10 40 30 50 20
```

**Sample Output**

```
14.1
```

[Explanation](https://www.youtube.com/watch?v=dq_D30kyR1A) of the standart deviation.