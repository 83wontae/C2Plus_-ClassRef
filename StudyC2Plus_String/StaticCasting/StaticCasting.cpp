#include <stdio.h>
#include <iostream>

class CBase {
public:
	int a = 1;
};

class CChild1 : public CBase {
public:
	void printB() {
		printf("CChild1::f()=%f\n", b);
	}

	float b = 3.14f;
};

class CChild2 : public CBase {
public:
	void printB() {
		printf("CChild2::f()=%d\n", c);
	}

	int c = 3;
};

int main()
{
	CBase* pBase = new CChild1;
	//b->printB();// b�� Base* �̱� ������ printB�� ������ �Ұ���

	// �⺻���� �ɽ��� ���
	// ������ CBase* �����Ϳ� �޸𸮸� CChild* ������ �޸� Ʋ�� ���� �о�´�.
	CChild1* pChild1 = (CChild1*)pBase;
	pChild1->printB();
	// �Ʒ��� ���� ����Ʈ�� �߸� ����Ű�� �Ǽ��� �� ��� ������ ���� �� �ִ�.
	// ������ int* �����Ϳ� �޸𸮸� CChild*�� �����. 
	// ���� ���� �ʾ� ������ ���� ������ ���� ���� �����ϵ�
	// ��� ������ �߻��ߴ��� ã�� �����
	int* a = new int(0);
	pChild1 = (CChild1*)a;

	// static_cast: ���� (������ �ܰ迡�� ��ȯ)
	// ������ int* �����Ϳ� �޸𸮸� CChild*�� ���߷��� �ϸ� ������ �Ұ�
	// ���� "�߸��� ���� ��ȯ�Դϴ�."
	// child = static_cast<CChild*>(a);
	// CBase*�� ���������� �б� ��ȯ ����
	pChild1 = static_cast<CChild1*>(pBase);
	pChild1->printB();

	// static_cast�� �θ��� ���¸� Ȯ��, ������ �ܰ迡�� ����ǹǷ� � ���°� ������ �˼� ����
	// �ڽ��� �ٸ��� Ȯ������ �ʱ� ������ ����X, ������ ����X ���������� �����
	// ��� ������ �߻��ߴ��� ã�� �����
	// �ݵ�� ĳ�����ϴ� ����� ���¸� Ȯ���ؾ���
	CBase* pBase2 = new CChild1;
	CChild2 *pChild2 = static_cast<CChild2*>(pBase2);
	pChild2->printB();// CChild1�� 3.14f���� CChild2�� int������ �޸𸮸� �о ���

	// float�� int������ ������ �޸𸮸� �о ����ؼ� 3.14f�� int ������ �� Ȯ��
	float pF = 3.14f;
	int* pI = (int*)&pF;
	printf("b=%d", *pI);

	delete pBase;
	delete pBase2;
}