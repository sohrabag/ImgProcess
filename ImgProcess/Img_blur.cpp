/*
				File name: Img_blur.cpp
				This file contains code which blurs an image using convolution method in image processing
				link: https://open.kattis.com/problems/imageprocessing
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

int main(void) {

	//Img vector
	std::vector< std::vector<int> > mat_Img;
	std::vector < std::vector<int> > mat_kernel;
	std::vector < std::vector<int> > mat_out_Img;
	std::stack <int> flip_stk;
	int pop_elm(0);
	std::vector<int> H_W_N_M_list;

	//reading input data
	std::string strline;
	int start(0), found(0), 
		H(0), W(0), N(0), M(0), c(0);
	
	std::getline(std::cin, strline);

	found = strline.find_first_of(' ');
	if(found != std::string::npos){
		H_W_N_M_list.push_back(::atoi(strline.substr(start, found - start).c_str()));
		start = found;
	}
	else
		return 1;

	for (unsigned i = 1; i < strline.length()-1 && found != std::string::npos; ++i) {
		
		found = strline.find_first_of(' ', found+1);
		if(found != std::string::npos){
			H_W_N_M_list.push_back(::atoi(strline.substr(start, found+1 - start).c_str()));
			start = found;
		}
	}

	H_W_N_M_list.push_back(::atoi(strline.substr(start+1, strline.length() - start +1).c_str()));
	//init H, W, N, M values.
	H = H_W_N_M_list[0]; W = H_W_N_M_list[1]; N = H_W_N_M_list[2]; M = H_W_N_M_list[3];

	start = 0; found = 0;
	mat_Img.resize(H);
	//fetch image from input: the nex H lines has W numbers which give a HXM size image.
	mat_Img[0].resize(W);

	for (int i = 0; i < H; ++i) {
			std::getline(std::cin, strline);
			if(i > 0) mat_Img[i].resize(W);

			start = 0; found = 0;
			found = strline.find_first_of(' ');
			if (found != std::string::npos) {
				mat_Img[i][0] = ::atoi(strline.substr(start, found - start).c_str());
				start = found;
			}
			else
				return 1;

			for (int j = 1; j < W; ++j) {

				found = strline.find_first_of(' ', found + 1);
				if (found != std::string::npos) {
					mat_Img[i][j] = ::atoi(strline.substr(start, found + 1 - start).c_str());
					start = found;
				}
			}
			mat_Img[i][W-1] = ::atoi(strline.substr(start + 1, strline.length() - start + 1).c_str());
		}

	//Extract Kernel values from input
	start = found = 0; strline.clear();
	mat_kernel.resize(N); //M is the width of the kernel matrix
	mat_kernel[0].resize(M); // N is the height of the kernel matrix

	for (int i = 0; i < N; ++i) {
		if (i > 0) mat_kernel[i].resize(M);
		std::getline(std::cin, strline);

		start = found = 0;
		found = strline.find_first_of(' ');
		if (found != std::string::npos)
			mat_kernel[i][0] = ::atoi(strline.substr(start, found - start).c_str());
		else
			return 1;

		start = found;

		for (int j = 1; j < M; j++) {

			found = strline.find_first_of(' ', found + 1);
			if (found != std::string::npos)
				mat_kernel[i][j] = ::atoi(strline.substr(start, found - start).c_str());
			else
				mat_kernel[i][j] = ::atoi(strline.substr(start+1, strline.length() - start+1).c_str());

			start = found;
		}
	}

	//flip row and columns of the kernel matrix
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			flip_stk.push(mat_kernel[i][j]);

	//pop the values out of stack and put it inside the new kernel matrix
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			pop_elm = flip_stk.top();
			flip_stk.pop();
			mat_kernel[i][j] = pop_elm;
		}

	//linear filtering using convolution
	mat_out_Img.resize(H - 1);
	for (int i = 0; i < H - 1; ++i)
		mat_out_Img[i].resize(W - 1);

	int res(0);
	for (int i = 0; i < H - 1; ++i)
		for (int j = 0; j < W - 1; ++j) {
			res = 0;
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < M; ++l)
				{
					res += mat_Img[i + k][j + l] * mat_kernel[k][l];
				}
			}
			std::cout << res << " ";
			mat_out_Img[i][j] = res;
		}

	return 0;
}