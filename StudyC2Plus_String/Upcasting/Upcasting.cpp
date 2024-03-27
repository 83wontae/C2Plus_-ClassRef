#include <stdio.h>
#include <iostream>

class CAnimal
{
public:
	float xpos = 1;
	float ypos = 2;
};

class CFlyingAnimal : public CAnimal
{
public:
	float zpos = 3;
};

// 배열을 넘겨주었기 때문에 문제가 생김
void printAnimals(CAnimal *animal, int n)
{
	// CAnimal은 8Byte
	// CFlyingAnimal은 12Byte
	// CFlyingAnimal이 넘어왔다면 12Byte 배열을 CAnimal로 묵시적 형변환을 해서 8Byte로 끊어서 읽는다.
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%f, ypos=%f\n", animal[i].xpos, animal[i].ypos);
	}
}

// 배열을 넘겨주었기 때문에 문제가 생김
void printAnimals2(CAnimal** animal, int n)
{
	// CAnimal은 8Byte
	// CFlyingAnimal은 12Byte
	// CFlyingAnimal이 넘어왔다면 12Byte 배열을 CAnimal로 묵시적 형변환을 해서 8Byte로 끊어서 읽는다.
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%f, ypos=%f\n", animal[i]->xpos, animal[i]->ypos);
	}
}

int main()
{
	/*
	// 해결책 하지만 STL을 사용하는게 편함
	CAnimal **animals = new CAnimal*[10];// CAnimal 가르키고 있는 포인터를 배열로 생성
	for(int i = 0; i < 10; i++)
	{
		animals[i] = new CFlyingAnimal;// CAnimal 가르키고 있는 포인터에 CFlyingAnimal 할당
	}
	printAnimals2(animals, 10);
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];// CAnimal 가르키고 있는 포인터에 CFlyingAnimal 해제
	}
	delete[] animals;
	*/

	CFlyingAnimal *animals = new CFlyingAnimal[10];
	printAnimals(animals, 10);
	delete[] animals;
}