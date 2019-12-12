# Problem Solving

## Simple Array Sum

## Compare the Triplets

Alice and Bob each created one problem. 
A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for
 three categories: problem clarity, originality, and difficulty.

We define the rating for Alice's challenge to be the triplet 
_a = (a[0], a[1], a[2])_, and the rating for Bob's challenge to be the 
triplet _b = (b[0], b[1], b[2])_.

Your task is to find their comparison points by comparing a[0] with b[0,
 a[1] with b[1], and a[2] with b[2].

If a[i] > b[i], then Alice is awarded  point.
If b[i] > a[i], then Bob is awarded  point.
If a[i] = b[i], then neither person receives a point.
Comparison points is the total points a person earned.

Given _a_ and _b_, determine their respective comparison points.

For example, a = [1, 2, 3] and b = [3, 2, 1]. For elements 0, Bob is awarded 
a point because a[0] < b[0]. For the equal elements a[1] and b[1], no points
 are earned. Finally, for elements 2, a[2] > b[2] so Alice receives a point.
 Your return array would be [1, 1] with Alice's score first and Bob's second.

**Constraints**

0 < a[i] <= 100
0 < b[i] <= 100

**Sample Input**

```
5 6 7
3 6 10
```


**Sample Output**

```
1 1
```

## A very big sum

## Diagonal Difference
Given a square matrix, calculate the absolute difference between the sums of its diagonals.

For example, the square matrix  is shown below:

```
1 2 3
4 5 6
9 8 9 
```

The left-to-right diagonal = 1 + 5 + 9 = 15. 
The right to left diagonal = 3 + 5 + 9 = 17.
Their absolute difference is |15 - 17| = 2.

**Constraints**

-100 < arr[i][j] <= 100

**Sample Input**

```
3
11 2 4
4 5 6
10 8 -12
```


**Sample Output**

```
15
```


## Plus Minus

Given an array of integers, calculate the fractions of its elements that are positive, negative, and are zeros. Print the decimal value of each fraction on a new line.

> Note: This challenge introduces precision problems. The test cases are scaled to six decimal places, though answers with absolute error of up to 10^(-4) are acceptable.

For example, given the array arr = [1, 1, 0, -1, -1] there are 5 elements, two positive, two negative and one zero. Their ratios would be 2/5,  2/5 and 1/5. It should be printed as

```
0.400000
0.400000
0.200000
```

**Constraints**

0 < n <= 100
-100 < arr[i] <= 100

**Sample Input**

```
6
-4 3 -9 0 4 1
```


**Sample Output**

```
0.500000
0.333333
0.166667
```

## Staircase
Consider a staircase of size n = 4:

```
   #
  ##
 ###
####
```

Observe that its base and height are both equal to n, and the image is drawn using # symbols and spaces. The last line is not preceded by any spaces.

Write a program that prints a staircase of size n.


**Constraints**

0 < n <= 100

**Sample Input**

```
6
```


**Sample Output**

```
     #
    ##
   ###
  ####
 #####
######
```

# Sum of Digits of a Five Digit Number
In this challenge, you have to input a five digit number and print the sum of digits of the number.

The input contains a single five digit number, n.

In order to get the last digit of a number, we use modulo operator \%. When the number is modulo divided by 10 we get the last digit.

To find first digit of a number we divide the given number by 10 until number is greater than 10. At the end we are left with the first digit.

**Constraints**

10000 <= n <= 99999

**Sample Input**

```
10564
```


**Sample Output**

```
16
```