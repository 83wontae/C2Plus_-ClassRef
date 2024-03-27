#pragma once
#include <iostream>

using namespace std;

class VecF
{
	//백터의 크기 (vec1개-float3개, vec2개-float6개, vec3개-float9개)
	//float에 갯수
	int n;
	float* arr;		//벡터의 float 값에 배열 정보 포인터

public:
	VecF(int d, float* a = nullptr) : n{ d } {
		arr = new float[d];//arr에 float형 d배열 공간 생성
		if (a) memcpy(arr, a, sizeof(float) * n);//arr에 a값을 "sizeof(float) * n"크기 만큼 복사한다.
	}
	//VecF(const VecF& fv) : n{ fv.n }, arr { fv.arr	} {} //arr주소가 그대로 복사되어 얕은 복사 문제가 생김
	VecF(const VecF& fv) : n{ fv.n } {
		arr = new float[n];
		memcpy(arr, fv.arr, sizeof(float) * n);
	}
	~VecF() {
		delete[] arr;
	}

	VecF add(const VecF& fv) const {
		VecF tmp{ n };
		for (int i = 0; i < n; ++i)
		{
			tmp.arr[i] = arr[i] + fv.arr[i];
		}
		return tmp;
	}

	void print() const {
		cout << "[ ";
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << "]";
	}
};

