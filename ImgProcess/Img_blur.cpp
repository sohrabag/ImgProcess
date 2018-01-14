/*
				File name: Img_blur.cpp
				This file contains code which blurs an image using convolution method in image processing
				link: https://open.kattis.com/problems/imageprocessing
*/
#include <iostream>
#include <vector>
#include <string>

int main(void) {

	//Img vector
	std::vector< std::vector<int> > mat_Img;
	std::vector < std::vector<int> > mat_kernel;
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
#if 1
			start = 0; found = 0;
			found = strline.find_first_of(' ');
			if (found != std::string::npos) {
				mat_Img[i][0] = ::atoi(strline.substr(start, found - start).c_str());
				start = found;
			}
			else
				return 1;
#endif
			for (int j = 1; j < W; ++j) {

				found = strline.find_first_of(' ', found + 1);
				if (found != std::string::npos) {
					mat_Img[i][j] = ::atoi(strline.substr(start, found + 1 - start).c_str());
					start = found;
				}
			}
			mat_Img[i][W-1] = ::atoi(strline.substr(start + 1, strline.length() - start + 1).c_str());
		}


	return 0;
}