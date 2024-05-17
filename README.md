# JPC-II Editorial
This is the official editorial for AASF JPC-II.

Also, fill this [feedback form](https://forms.gle/g5hBL71arjBGFwQq6) form to let me know about your experience, at the end of this tutorial. I am eager to hear from you.

### Problem Author and Editorialist: [Ayush Sah](https://www.linkedin.com/in/ay-ew-sh/)

### Problem Testers: [Pranav Jarande](https://www.linkedin.com/in/pranav-jarande-997a22257/), [Aditya Bharadwaj](https://www.linkedin.com/in/aditya-bharadwaj-134847157/)
<details>
<summary>Quick shoutout to the unofficial testers:</summary>
NonTechNerd69, Sohail, Hippie for their valuable feedback! :heart:
</details>

## 1. Aparecium!
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

[Author's Solution](1.%20Aparecium/author's_solution.cpp)

[Tester1's Solution]()

[Tester2's Solution]()

## 2. One Must Imagine Sisyphus Happy
<details>
<summary>Tag(s)</summary>

  `Game` `String` `Greedy` `Sorting`
</details>
<details>
<summary>Hint</summary>

  When does Kafka have advantage over Camus?
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

[Author's Solution](2.%20One%20Must%20Imagine%20Sisyphus%20Happy/author's_solution.cpp)

[Tester1's Solution]()

[Tester2's Solution]()

## 3. Rivendell Recovery
<details>
<summary>Tag(s)</summary>

  `Search` `Simulation` `Sorting` `Policy Based Data Structure`
</details>
<details>
<summary>Hint</summary>

```What if we maintained an array of unoccupied seats and simulated the whole process?```
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

**Time Complexity:** $O(N\log{N}+log(abs(N-M)$
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1100
</details>

[Author's Solution](3.%20Rivendell%20Recovery/author's_solution.cpp)

[Author's Alternative Solution](3.%20Rivendell%20Recovery/author's_alternative_solution.cpp)

[Tester1's Solution]()

[Tester2's Solution]()

## 4. Saladin's Sword Swap Conundrum
<details>
<summary>Tag(s)</summary>

  `Array Shifting` `Derangement` 
</details>
<details>
<summary>Hint</summary>

```This is a problem of derangement. How is the possibility of a possible derangement related to the count of each element?```
</details>
<details>
<summary>Tutorial</summary>

Derangement can be defined as an arrangement in which no element is in its original position. Thus, it is easy to figure out that in this problem that if we can make a valid derangement of the given sequence, then Baldwin wins. But, doing it in a naive way would be computationally difficult. So, instead of embarking upon the journey to print this derangement let us first figure out if there is a way to determine whether Baldwin can even win or not. Upon inspection of few examples, we can make a key observation that if the count of any element in the sequence is more than $\left\lfloor\frac{N}{2}\right \rfloor$ then it is not possible to generate a derangement. Let's prove it:
``` 
PROOF

STATEMENT: If an element occurs more than 'half the size' number of times in an array then the derangement of that array is not possible.
Let us say that it is possible to make a derangement even if an element's count is more than half of the total input size. So, to generate the derangement we try to pick this number and at every occurrence of it,  we fill the remaining numbers in. But, eventually we run out of remaining numbers as there would always be atleast 1 empty position where nothing but this selected element could only go in. This arrangement is not a valid derangement.
Hence, by contradiction we prove our statement.
```
Thus, Baldwin can only win if all elements occur less than $\left\lfloor\frac{N}{2}\right \rfloor$ times. 

Now, to generate a valid derangement we can take help of a result of our result above. If we can have all the same coloured sheaths in a line, then we know that the colour appearing for the most number of times would also require most number of other remaining colours to fill their position. So, if we rotate this sorted sequence by an amount of $\left\lfloor\frac{N}{2}\right \rfloor$, then we can guarantee that no element of maximum occurence is in its original position. Thus as a result of the statement that we proved and this observation, we ensure that we get a valid derangement and none of the elements are in their original position.
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1400
</details>

[Author's Solution](4.%20Saladin's%20Sword%20Swap%20Conundrum/author's_solution.cpp)

[Tester1's Solution]()

[Tester2's Solution]()

## 5. YZY App Subscription
<details>
<summary>Tag(s)</summary>

  `Coordinate Compression` `Sorting` `Difference Array` `Sweep Line`
</details>
<details>
<summary>Hint</summary>
</details>
<details>
<summary>Tutorial</summary>
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1500
</details>

[Author's Solution](5.%20YZY%20App%20Subscription/author's_solution.cpp)

[Tester1's Solution]()

[Tester2's Solution]()

## 6. ICPC Team
<details>
<summary>Tag(s)</summary>

  `Binary Search` `Bitmasking` `DP`
</details>
<details>
<summary>Hint</summary>
</details>
<details>
<summary>Tutorial</summary>
</details>
<details>
<summary>Problem Rating (Equivalent to Codeforces)</summary>
   
  > 1700
</details>

[Author's Solution](6.%20ICPC%20Team/author's_solution.cpp)

# Thanks for taking part in this contest!
[If you wish, you can now go back to filling the feedback form.](https://forms.gle/g5hBL71arjBGFwQq6)
