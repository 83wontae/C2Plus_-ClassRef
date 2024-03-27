#include <stdio.h>
#include <iostream>

class CBase { // ���� �Լ��� �ϳ��� �ָ� "������ Ŭ����" ��� �Ѵ�.
public:
	// ���� �Լ�
	// virtual Ű���带 �Լ� �տ� ���δ�.
	// �ڽ� Ŭ�������� �Լ��� override�� �ؼ� �籸�� ����
	// RTTI (Run Time Type Information/Identification) ������ �����
	// RTTI ��?
	// ���� �Լ��� �Ǹ��� �߰������� "����"�� �Ҵ��̵�
	// �߰��� �Ҵ�� �������� Ŭ������ ������ ����Ű�� ��
	// dynamic_cast�� Ŭ������ ũ�⸦ �����ϴ°� �ƴ϶� �߰��� �Ҵ�� �������� Ŭ������ ������ ����
	virtual void printX() {
		printf("CBase printX=%d\n", x);
	}

	int x = 10;
};

class CChild1 : public CBase {
public:
	void printY() {
		printf("CBase printY=%d\n", y);
	}

	int y = 20;
};

class CChild2 : public CBase {
public:
	void printZ() {
		printf("CBase printZ=%d\n", z);
	}

	int z = 30;
};

int main()
{
	// dynamic_cast : ���� (��Ÿ�ӿ� ĳ����)
	// RTTI (Run Time Type Information/Identification)
	printf("CBase Size=%I64d\n", sizeof(CBase));// CBase Ŭ���� ũ�� ���
	printf("CBase Size=%I64d\n", sizeof(CChild1));// CChild1 Ŭ���� ũ�� ���

	int64_t* a = (int64_t*)new CBase;
	printf("a[0]=%I64d, a[1]=%d\n", a[0], (int)a[1]);// CBase Ŭ���� ũ�� ���

	int64_t* b = (int64_t*)new CChild1;
	printf("a[0]=%I64d, a[1]=%d, a[2]=%d\n", b[0], (int)b[1], (int)b[2]);// CBase Ŭ���� ũ�� ���

	delete a;
	delete b;

	CBase* pBase[] = { new CChild1(), new CChild2() };

	for (CBase* pB : pBase)
	{
		pB->printX();

		CChild1* pChild = dynamic_cast<CChild1*>(pB);// dynamic_cast ĳ���� �� ��� ������ ����Ʈ�� �޴´�.
		if (pChild != nullptr)// ���������� �޸𸮸� �о��ٸ� ��ü�� ������ ���� �� �ְ� �ƴϸ�, nullptr ���� ����ִ�.
		{
			pChild->printY();
		}
	}

	for (CBase* pB : pBase)
	{
		delete pB;
	}
}