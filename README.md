# ImgProcess
Image Processing project
//This file contains a cplusplus program which takes an image of certain size
//and creates effects such as blur on the image and outputs it. 
//image bluring is done by convolution between the original image and a kernel.
//kernel is like a filter that moves gradually over an image and then multiply
//locally with overlapped part of image and summation of this multiplication
//will replace that area of original image. result of this is an smaller size image
//Input:
/*
Input
The first line of the input contains four integers, HH, the height of the image, WW, the width of the image, NN, 
the height of the kernel, and MM, the width of the kernel (1≤H≤201≤H≤20, 1≤W≤201≤W≤20, 1≤N≤H1≤N≤H, 1≤M≤W1≤M≤W).

Each of the next HH lines contains WW integers, between 00 and 100100 inclusive, representing the image.

Each of the next NN lines contains MM integers, between 00 and 100100 inclusive, representing the kernel.

Output
Output the resulting image after convolution, consisting of H−N+1H−N+1 lines, each with W−M+1W−M+1 integers.

Sample Input 1	Sample Output 1
4 4 2 2			26 36 46
				66 76 86
				106 116 126
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1 2
3 4

*/
