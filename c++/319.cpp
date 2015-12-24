// First time. 2015/12/24
// This problem has a simple math solution.
// Bulb i is on iff it is toggled an odd number of times.
// Bulb i is toggled in round m iff m divides i.
// Any number has an even number of divisors, except square numbers.
// Therefore bulbs 1, 4, 9, 16... will be on eventually.

class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
