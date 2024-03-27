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

// �迭�� �Ѱ��־��� ������ ������ ����
void printAnimals(CAnimal *animal, int n)
{
	// CAnimal�� 8Byte
	// CFlyingAnimal�� 12Byte
	// CFlyingAnimal�� �Ѿ�Դٸ� 12Byte �迭�� CAnimal�� ������ ����ȯ�� �ؼ� 8Byte�� ��� �д´�.
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%f, ypos=%f\n", animal[i].xpos, animal[i].ypos);
	}
}

// �迭�� �Ѱ��־��� ������ ������ ����
void printAnimals2(CAnimal** animal, int n)
{
	// CAnimal�� 8Byte
	// CFlyingAnimal�� 12Byte
	// CFlyingAnimal�� �Ѿ�Դٸ� 12Byte �迭�� CAnimal�� ������ ����ȯ�� �ؼ� 8Byte�� ��� �д´�.
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%f, ypos=%f\n", animal[i]->xpos, animal[i]->ypos);
	}
}

int main()
{
	/*
	// �ذ�å ������ STL�� ����ϴ°� ����
	CAnimal **animals = new CAnimal*[10];// CAnimal ����Ű�� �ִ� �����͸� �迭�� ����
	for(int i = 0; i < 10; i++)
	{
		animals[i] = new CFlyingAnimal;// CAnimal ����Ű�� �ִ� �����Ϳ� CFlyingAnimal �Ҵ�
	}
	printAnimals2(animals, 10);
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];// CAnimal ����Ű�� �ִ� �����Ϳ� CFlyingAnimal ����
	}
	delete[] animals;
	*/

	CFlyingAnimal *animals = new CFlyingAnimal[10];
	printAnimals(animals, 10);
	delete[] animals;
}