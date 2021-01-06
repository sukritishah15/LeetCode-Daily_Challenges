/* 
Link to problem :
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/
*/

/*
Method 1 - Use a set 
Loop through the given array of numbers
If the number exists in the set, remove the number from the set.
Else, add the number to the set.
Return the only number left in the set, at the end. 

Time Complexity - O(n^2) --> Since, we loop through the set for every element in the array
Space Complexity - O(n) --> Since, we use extra space for set
*/

// Method - 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
            else{
                s.erase(nums[i]);
            }
        }
        return (*s.begin());
    }
};

/*
Method 2 - Use a map 
Loop through the given array of numbers, increase the frequency of the number in the map.
In the map, number will be mapped to frequency of that number in the array.
Loop through the map, if we find a number whose frequency is 1, return that number.

Time Complexity - O(n) --> Since, we loop through the array once
Space Complexity - O(n) --> Since, we use extra space for map
*/

// Method - 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto x : mp){
            if(x.second==1)
                ans = x.first;
        }
        return ans;
    }
};

/*
Method 3 - Mathematical Logic
Maintain a set, add numbers to this set, while looping through the array.
While looping through the array, maintain sum of numbers in the array, call it sumOfArray.
Calculate the sum of all the numbers, in the set, call it sumOfSet.
If, all the numbers existed in pairs, then twice the sumOfSet would have been equal to sumOfArray.
But, since 1 number is unique, 
the difference of (2*sumOfSet) and the sumOfArray will give that unique / single no.

Time Complexity - O(n) --> Since, we loop through the array once and through the set also once.
Space Complexity - O(n) --> Since, we use extra space for set.
*/

// Method - 3
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        int sumOfSet = 0, sumOfArray = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            s.insert(nums[i]);
            sumOfArray += nums[i];
        }
        for(auto x : s){
            sumOfSet += x;
        }
        return (2*sumOfSet - sumOfArray);
    }
};

/*
Method 4 - XOR Operator
Logic - 
        XOR of a number with itself yields 0
        XOR of a number with 0 yields the number itself
All the numbers that exist in pairs, will give 0 as result
And the single number will yield itself, when XOR operator will be applied 
on this number and the result (which is 0), so far

Time Complexity - O(n) --> Since, we loop through the array once.
Space Complexity - O(1) 
*/

// Method - 4
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            res = res^nums[i];
        }
        return res;
    }
};
