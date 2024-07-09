/*
Here is the full question from the images:

---

**Code Question 1**

Amazon's AWS provides fast and efficient server solutions. The developers want to stress-test the quality of the servers' channels. They must ensure the following:
- Each of the packets must be sent via a single channel.
- Each of the channels must transfer at least one packet.

The **quality** of the transfer for a channel is defined by the median of the sizes of all the data packets sent through that channel.

**Note**: The median of an array is the middle element if the array is sorted in non-decreasing order. If the number of elements in the array is even, the median is the average of the two middle elements.

Find the maximum possible sum of the qualities of all channels. If the answer is a floating-point value, round it to the next higher integer.

**Example**

packets = [1, 2, 3, 4, 5]
channels = 2

At least one packet has to go through each of the 2 channels. One maximal solution is to transfer packets {1, 2, 3, 4} through channel 1 and packet {5} through channel 2.

|   |   |   |   |
|---|---|---|---|
| 1 | 2 | 3 | 4 |

Channel 1

|   |   |   |   |
|---|---|---|---|
| 5 |   |   |   |

Channel 2

The quality of transfer for channel 1 is (2 + 3)/2 = 2.5 and that of channel 2 is 5. Their sum is 2.5 + 5 = 7.5 which rounds up to 8.

**Function Description**

Complete the function `findMaximumQuality` in the editor below.
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main()
{
}