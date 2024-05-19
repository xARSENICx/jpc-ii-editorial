# JPC-II Editorial
This is the official editorial for [AASF JPC-II](https://www.hackerrank.com/junior-programming-contest-ii).

Also, fill this [feedback form](https://forms.gle/g5hBL71arjBGFwQq6) form to let me know about your experience, at the end of this tutorial. I am eager to hear from you.

### Problem Author and Editorialist: [Ayush Sah](https://www.linkedin.com/in/ay-ew-sh/)

### Problem Testers: [Pranav Jarande](https://www.linkedin.com/in/pranav-jarande-997a22257/), [Aditya Bharadwaj](https://www.linkedin.com/in/aditya-bharadwaj-134847157/)
<details>
<summary>Quick shoutout to the unofficial testers:</summary>
NonTechNerd69, Sohail, Hippie for their valuable feedback! :heart:
Also, thanks Pratyush for editing the artwork in the first problem. :heart:
</details>

## 1. [Aparecium!](https://www.hackerrank.com/contests/junior-programming-contest-ii/challenges/aparecium)
<details>
<summary>Tag(s)</summary>

  `String` `String Matching` `Hash Table` `2 Pointers`
</details>
<details>
<summary>Hint</summary>

```
Do what the problem says.
```
</details>
<details>
<summary>Tutorial</summary>

  Iterate over the whole string and store the string of length 2 by concatenating the current and the next character in a hash set. For every $i$, reverse this string and check whether it already exists in the hash set or not. If it does, return True. Otherwise, return False.

**Time Complexity**: O(N)
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
  
  > 800
</details>

[Author's Solution](1.%20Aparecium/author's_solution.cpp#L191)

[Tester1's Solution](1.%20Aparecium/tester1's_solution.cpp)

[Tester2's Solution](1.%20Aparecium/tester2's_solution.cpp)

## 2. [One Must Imagine Sisyphus Happy](https://www.hackerrank.com/contests/junior-programming-contest-ii/challenges/kafkacamus)
<details>
<summary>Tag(s)</summary>

  `Game` `String` `Greedy` `Sorting`
</details>
<details>
<summary>Hint</summary>

```
  When does Kafka have advantage over Camus?
```
</details>
<details>
<summary>Tutorial</summary>

  Let us assume that, the total number of common words known to both are $k$. Now, to play optimally each of them should first exhaust the common list of words (Why?). So, if we can find out when Kafka has advantage over Camus then we can determine who the winner would be. It is obvious that the one who knows more words wins. So, the situation of advantage arises when both of them know the exact same number of words.

For this case, it is easy to observe that Kafka has an advantage over Camus when the count of common words is odd. This is because, for each common word that Kafka uses, Camus loses that word. Eventually, Kafka ending up using the last common word always. This would mean that Kafka would have **effectively** 1 more word than Camus and would thus win as $n+1 > m$, when $n = m$.

**Time Complexity:** $O((n+m)\log{|String|})$
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1000
</details>

[Author's Solution](2.%20One%20Must%20Imagine%20Sisyphus%20Happy/author's_solution.cpp#L191)

[Tester1's Solution](2.%20One%20Must%20Imagine%20Sisyphus%20Happy/tester1's_solution.cpp)

[Tester2's Solution](2.%20One%20Must%20Imagine%20Sisyphus%20Happy/tester2's_solution.cpp)

## 3. [Rivendell Recovery](https://www.hackerrank.com/contests/junior-programming-contest-ii/challenges/rivendell)
<details>
<summary>Tag(s)</summary>

  `Search` `Simulation` `Sorting` `Policy Based Data Structure`
</details>
<details>
<summary>Hint</summary>

```
What if we maintained an array of unoccupied seats and simulated the whole process?
```
</details>
<details>
<summary>Tutorial #1</summary>

This is a straight forward problem of simulation. One such way to solve the problem is described here. Maintain an array of size n where each seat is initially unoccupied, denoted by -1. Iterate over this array and update the seat with the value 0 as they get occupied. Now, iterate over this updated array and from the very first seat which is unoccupied, increment the seat number starting from 1. Finally, do a linear search over this array to find the original seat number. 

Since, the constraints aren't very strict, a solution till $O(N\log{N}$ or $O(M\log{M})$ would pass as well. Although a brute implementation worse than this would give you TLE.

**Time Complexity:** $O(N)$
</details>
<details>
<summary>Tutorial #2</summary>

  This problem can be solved with the help of an ordered set from the [policy based data structure](https://codeforces.com/blog/entry/11080) class which gives all the basic operations that an STL ordered set gives, alongwith two extra functions `find_by_order()` and `order_of_key()`. Although, using this data structure here would result in a worse time complexity than [author's solution](3.%20Rivendell%20Recovery/author's_solution.cpp), it is still a very powerful data structure to learn. It helps to solve offline query based problems for example, in a very elegant way. The solution code can be found in [author's alternative solution](3.%20Rivendell%20Recovery/author's_alternative_solution.cpp).

Here is the extended version of the problem to try this method: https://www.thejoboverflow.com/problem/148/

**Time Complexity:** $O(N\log{N}+log(abs(N-M)))$
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1100
</details>

[Author's Solution](3.%20Rivendell%20Recovery/author's_solution.cpp#L184)

[Author's Alternative Solution](3.%20Rivendell%20Recovery/author's_alternative_solution.cpp)

[Tester1's Solution](3.%20Rivendell%20Recovery/tester1's_solution.cpp)

[Tester2's Solution](3.%20Rivendell%20Recovery/tester2's_solution.cpp)

## 4. [Saladin's Sword Swap Conundrum](https://www.hackerrank.com/contests/junior-programming-contest-ii/challenges/saladin)
<details>
<summary>Tag(s)</summary>

  `Array Shifting` `Derangement` 
</details>
<details>
<summary>Hint</summary>

```
This is a problem of derangement. How is the possibility of a possible derangement related to the count of each element?
```
</details>
<details>
<summary>Tutorial</summary>

Derangement can be defined as an arrangement in which no element is in its original position. Thus, it is easy to figure out that in this problem, if we can make a valid derangement of the given sequence, then Baldwin wins. But, doing it in a naive way would be computationally difficult. So, instead of embarking upon the journey to print this derangement let us first figure out if there is a way to determine whether Baldwin can even win or not. Upon inspection of few examples, we can make a key observation that if the count of any element in the sequence is more than $\left\lfloor\frac{N}{2}\right \rfloor$, it is not possible to generate a derangement. Let's prove it:
``` 
PROOF

STATEMENT: If an element occurs more than 'half the size' number of times in an array then the derangement of that array is not possible.
Let us say that it is possible to make a derangement even if an element's count is more than half of the total input size.
So, to generate the derangement we try to pick this number and at every occurrence of it,  we fill the remaining numbers in.
But, eventually we run out of remaining numbers as there would always be atleast 1 empty position where nothing but this selected element could only go in.
This arrangement is not a valid derangement.
Hence, by contradiction we prove our statement.
```
Thus, Baldwin can only win if all elements occur not more than $\left\lfloor\frac{N}{2}\right \rfloor$ times. 

Now, to generate a valid derangement we can take help of our result above. If we can have all the same coloured sheaths in a line, then we know that the colour appearing for the most number of times would also require most number of other remaining colours to fill their position. So, if we rotate this sorted sequence by an amount of $\left\lfloor\frac{N}{2}\right \rfloor$, then we can guarantee that no element of maximum occurence is in its original position. Thus as a result of the statement that we proved and this observation, we ensure that we get a valid derangement and none of the elements are in their original position.

**Time Complexity:** $O(N\log{N})$
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1400
</details>

[Author's Solution](4.%20Saladin's%20Sword%20Swap%20Conundrum/author's_solution.cpp#L185)

[Tester1's Solution](4.%20Saladin's%20Sword%20Swap%20Conundrum/tester1's_solution.cpp)

[Tester2's Solution](4.%20Saladin's%20Sword%20Swap%20Conundrum/tester2's_solution.cpp)

## 5. [YZY App Subscription](https://www.hackerrank.com/contests/junior-programming-contest-ii/challenges/yzyapp)
<details>
<summary>Tag(s)</summary>

  `Coordinate Compression` `Sorting` `Difference Array` `Sweep Line`
</details>
<details>
<summary>Hint</summary>

```
You have to find out the total cost incurred on each day without YZY Deluxe and compare and find out the better one.
```
</details>
<details>
<summary>Tutorial</summary>

  Since, the constraints over the number of days are very large, its not feasible to iterate over them and calculate the total sum. So, we instead use the coordinate compression technique since we only need the starting and ending days of each album. 

Assume you have an ifinite time length spanning over $[1, \infty)$. Now, for each pair of $(a_i,b_i)$ we can get our non-overlapping segments of time by splitting them over the time length. 
```
EXAMPLE
Say, the days are {1,5} and {4,10} for two albums. The finals time segments would be:
[1,3] [4,5] [6,10] [11, ∞) where [4,5] is the segment where both the albums are listened to.
These segments can also be viewed like this:
[1,4) [4,6) [6,11) [11, ∞)
```
So, now to represent these segments we only need to deal with the left end-points of each segment which are either $a_i$ or $b_i+1$ ( $\boxed{b_i+1}$ can be understood as the first day $i^{th}$ album isn't listened to). The reason for this is that, only the start or end day of an album listened to matters. Now, on the ${a_i}^{th}$ day, the toal cost would increase by a value of $c_i$ and on the ${b_i}^{th}$ day it will decrease by $c_i$.

After we get the segments, we now need to calculate the cost for **each segment**, and compare it with K, the price of the subscription. Thus, for implementation we can use a map (since we need the time stamps in a sorted manner) to store the change that is happening to the total cost on each critical day, i.e., the left end-points of each and every segment. At the, end we get the final total answer.

**Time Complexity:** $O(N\log{A})$ where A is the upper bound of binary search.

</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1500
</details>

[Author's Solution](5.%20YZY%20App%20Subscription/author's_solution.cpp#L191)

[Tester1's Solution](5.%20YZY%20App%20Subscription/tester1's_solution.cpp)

[Tester2's Solution](5.%20YZY%20App%20Subscription/tester2's_solution.cpp)

## 6. [ICPC Team](https://www.hackerrank.com/contests/junior-programming-contest-ii/challenges/icpcteam)
<details>
<summary>Tag(s)</summary>

  `Binary Search` `Bitmasking` `DP`
</details>
<details>
<summary>Hint</summary>

```
How can we represent a yes/no valued tuple in a quick way?
```
</details>
<details>
<summary>Tutorial</summary>

A naive brute force solution will give TLE as for the worst case, it will be in the order of $5 \times {3000 \choose 3} \approx 2 \times 10^{10}.$ So, we need to think of a better solution. Now, problems of the sort "maximum of minimum of value" or vice-verse can be reduced to a problem where we ask the question "Is there a possible answer more than a value x(say)?" and we get a series of Yes/No answers forming a predicate. Thus, we reduce our problem to a binary search over the answer problem. ([Refer to this blog for an explanation to build the intuition of binary search](https://www.topcoder.com/thrive/articles/Binary+Search#:~:text=%2D7.-,EXAMPLE,-At%20this%20point))

I won't be explaining the working of binary search as it would stretch the tutorial. You can find the dry run in an explained sample below.

The Yes/No question (the checker function) we have to get answer for, in our problem is-  Is the parameter greater than or equal to x (the middle value of binary search)? If it is, we set that bit as 1, otherwise 0 (This is the step of bitmasking). In this way, we need to find the masks for all the $n$ people. Since, there are only two option for each attribute we can have only $2^5$ maximum unique masks. Thus, we can get rid of repeated masks and only deal with the unique masks as we just have to maximise our efficiency(and not find out an actual combination of 3 people). Now, after generating these masks we need to take any 3 and check if the total overlap of all parameters is the complete power set mask or not, i.e.,  all the bits are set or not. This can be done in $2^5\times2^5\times2^5$ ways for the worst case as we got rid of repeated masks.

Here is an illustration of the sample testcase:
![Screenshot 2024-05-19 033304](https://github.com/xARSENICx/jpc-ii-editorial/assets/75406648/96f34618-4aad-446f-9bb8-f0174a187634)


**Time Complexity:** $O\left( \left( 5N+{\left( 2^{5} \right)}^3 \right )log(A) \right)$ where A is the upper limit of binary search.
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1700
</details>

[Author's Solution](6.%20ICPC%20Team/author's_solution.cpp#L187)

# Thanks for taking part in this contest!
Hope you enjoyed giving it and got something new to learn out of it. 

[If you wish, you can now go back to filling the feedback form.](https://forms.gle/g5hBL71arjBGFwQq6)
