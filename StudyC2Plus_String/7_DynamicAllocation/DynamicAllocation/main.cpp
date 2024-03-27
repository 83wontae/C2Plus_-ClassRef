#include <vector>
#include <list>

// C++ �� ������ ����
// C++ ���� �츮�� �ۼ��� �ҽ��ڵ带 ������ ������ �� �ִ� ���� ���Ϸ� ��ȯ�ϱ� ���ؼ��� �� 4 ���� �ܰ踦 ���ľ߸� �մϴ�.

// 1. ��ó��(Preprocessing) �ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� ��ó��(Preprocessing) �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ
// 4. ��ŷ(Linking) �ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ ����

// �޸� ����
// 1. Code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
// 2. Data ���� : ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
// 3. Stack ���� : ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ���� �Ǹ� �ý��ۿ� ��ȯ
// 4. Heap ���� : malloc �Ǵ� new �Լ� � ���ؼ� �������� �Ҵ�Ǵ� ����, malloc() �Ǵ� new �����ڸ� ���� �Ҵ�, free() �Ǵ� delete �����ڸ� ���� ����

struct stShop
{
	int Sales;
	int iPhone;
	int GalaxyS23;

	stShop() :Sales(0), iPhone(0), GalaxyS23(0)
	{

	}
};

bool IsSales100(const stShop& vi)
{
	return vi.Sales == 200;
}

int main()
{
	/*
	����(vector)
	* �������� �޸𸮸� Ȯ���Ѵ�.
	* �ڽ��� ��Ҹ� ������ ���� �迭 ( dynamic array )�� �����Ѵ�.
	* ���� ���� �����ڸ� ����([])�ϱ� ������ ��� ���� �����ϵ� ����ð�(������ �ð�)�� �ҿ�ȴ�
	* ���� �迭�̱� ������ �迭�� �߰��� ���� �߰��ϰų� �����ϸ� ���� ���� �̵��ؾ��ϱ� ������ ���� �ð��� �ɸ���
	* �߰��� �߰��ϴ� ���� ������尡 ũ�� ������ ���� �޺κп� �߰��Ѵ� ( push_back )
	* ���� �迭�̱� ������ ũ���� Ȯ��� ��Ұ� ���������� ���Ҵ� ����� ũ��.

	����
	* ���������� ����ð�(������ �ð�)�� �����ϴ�. ���� �б⿡ �ſ� ���ϴ�.

	����
	* �߰��� ���� �߰�/�����ϴ� ����� ũ��
	* ���Ҵ� ����� ũ��
	*/
	std::vector<int> vecInt{ 0,1,2,3,4 };// Stack ���� �Ҵ�
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt[1] = 100;
	int nTemp = vecInt[1];// ������ ����� �ε����� ������ ���������� undefined behaviour�̸� � ���� ��������� �� �� ����
	nTemp = vecInt.at(1);// ���ڿ��� ������ ����� �ε����� �����Ϸ� ��� out of range ���ܸ� �߻�
	int* pInt = vecInt.data();//���Ͱ� ������ ��Ҹ� �����ϱ� ���� ���������� ����ϴ� �޸� �迭�� ���� ���� �����͸� ��ȯ
	int vSize = vecInt.size();//������ ��� ���� ��ȯ
	int vCap = vecInt.capacity();//��� ���鿡�� ǥ���� ���� �� ���� �Ҵ�� ���� ������ ũ�⸦ ��ȯ

	// vector �迭�� �⺻ for���� ���
	for (int i = 0; i < vecInt.size(); i++)
	{
		printf("vecInt[%d] = %d\n", i, vecInt[i]);
	}

	// vector �迭�� �⺻ for each���� ���, ���� ����
	for (int num : vecInt)
	{
		printf("vecInt2 = %d\n", num);
		//num = 11;
	}

	// vector �迭�� �⺻ for each���� ���, ���۷��� ����
	for (const int& num : vecInt)// const ���� ���� �Ұ�
	{
		printf("vecInt1 = %d\n", num);
		//num = 11;
	}

	// vector �迭�� for iterator���� ���
	//for (auto itr = vecInt.begin(); itr != vecInt.end(); itr++)
	for (std::vector<int>::iterator itr = vecInt.begin(); itr != vecInt.end(); itr++)
	{
		printf("itr = %d\n", *itr);
		*itr = 22;
	}

	// vector���� Ư���� ���Ҹ� ���� �����ϱ� 
	std::vector<int>::iterator vecIter = vecInt.begin();
	while (vecIter != vecInt.end())
	{
		if (*vecIter == 22)
		{
			vecIter = vecInt.erase(vecIter);
		}
	}

	printf("vecInt size = %I64d\n", vecInt.size());

	/*
	����Ʈ(list)
	* ����Ʈ�� ��ҵ��� ����� ���Ḯ��Ʈ�� ���·� �����Ѵ�.(Doubly Linked List)
	* ����Ʈ ��ü�� ��Ŀ�� �Ҹ��� ������ 2���� �����ϴµ� �̴� head�� tail�� ����Ų��.
	* ���ο� ��Ҹ� �����ϱ� ���ؼ��� �� ������(��Ŀ)�� �����Ѵ�.
	* ����Ʈ�� ���� ����([])�� �������� �ʴ´�. (n��° ��ҿ� �����ϱ� ���ؼ� ������ ���ľ� �ϱ� ����)
	* Ư�� ��ġ�� �߰� / ������ �����Ӵ�. (Ư�� ��ġ�� ã�� �ð��� ����)
	* ���Ҵ� ������ ����.�������� �޸𸮰� �ƴϱ� ������(�޸𸮰� �����Ǵ� ��) ������ �߰��� �� �ִ�.

	����
	* ������ ��ġ�� ��Ҹ� �߰��ϴ� ���� �����Ӵ�(ã�ư��� �ð� ����) ���� ���⿡ �ſ� ���ϴ�
	����
	* ���������� �Ұ����ϱ� ������ ���� Ž���Ͽ� ��ġ�� ã�´�
	* ���Ұ��� ������ ���� �߰����� �޸𸮸� �Ҹ��Ѵ�(���� ����� ������ �޸�)
	*/
	std::list<int> listInt{ 0,1,2,3,4 };// Stack ���� �Ҵ�
	listInt.push_back(10);// ����Ʈ�� ���ʿ� ��� �߰�
	listInt.push_front(20);// ����Ʈ�� ���ʿ� ��� �߰�
	int lSize = listInt.size();// ����Ʈ�� ��� ���� ��ȯ

	//listInt[0] = 100;// ���� ���� ������([])�� ����Ҽ� ����

	// iterator(inner class list���� ���� �ּҰ� ã��
	std::list<int>::iterator iter = listInt.begin();
	++iter;
	--iter;
	int data = *iter;
	printf("data=%d\n", data);

	// list���� Ư�� ���� ã��
	auto it = std::find(listInt.begin(), listInt.end(), 1);
	if (it != listInt.end())
	{
		listInt.insert(it, 2023);
		listInt.emplace(it, 2024);
	}

	// list���� for each���� ����Ͽ� ���Ұ� ����ϱ�, ���� ����
	for (int num : listInt)
	{
		printf("listInt = %d\n", num);
		num = 11;
	}

	// list���� for each���� ����Ͽ� ���Ұ� ����ϱ�, ���۷��� ����
	for (const int& num: listInt)// const ���� ���� �Ұ�
	{
		printf("listInt = %d\n", num);
	}

	// ����ü list���� find_if�� ����Ͽ� Ư�� ���� ã��
	std::list<stShop> arrShop;
	stShop temp;
	temp.Sales = 0;
	temp.GalaxyS23 = 0;
	temp.iPhone = 0;
	arrShop.push_back(temp);
	temp.Sales = 100;
	arrShop.push_back(temp);
	temp.Sales = 200;
	arrShop.push_back(temp);
	temp.Sales = 300;
	arrShop.push_back(temp);

	std::list<stShop>::iterator it_shop = std::find_if(arrShop.begin(), arrShop.end()
		, IsSales100);
	//std::list<stShop>::iterator it_shop = std::find_if(arrShop.begin(), arrShop.end()
	//	, [](const stShop& vi) {return vi.Sales == 100; });

	if (it_shop != arrShop.end())
	{
		printf("Find Shop Sales = %d, iPhone = %d, GalaxyS23 = %d\n", it_shop->Sales, it_shop->iPhone, it_shop->GalaxyS23);
		it_shop->iPhone = 1000;
	}

	for (stShop& num : arrShop)
	{
		printf("arrShop Sales = %d, iPhone = %d, GalaxyS23 = %d\n", num.Sales, num.iPhone, num.GalaxyS23);
	}

	/*
	 - ���� �޸� �Ҵ�
	�������� �޸𸮸� �Ҵ��ϸ� ������ �� stack ������ �Ҵ�Ǹ�, �Լ��� �������� �� �Ҹ�ȴ�.
	���α׷� ������ �� stack�� �󸶸�ŭ�� ũ��� �Ҵ��� �ؾ��ϴ��� �����Ǳ� ������, ������ ���� ũ�Ⱑ ����� �� ����.
	���� ���� �迭 ���� �� ũ�⸦ ���������� ����ϸ� ������ �� �� �����Ƿ� �ݵ�� ����� ����ؾ� �Ѵ�.

	int a = 0;
	int arr[10];

	 - ���� �޸� �Ҵ�
	�������� �޸𸮸� �Ҵ��ϴ� ��� �����Ͱ� heap ������ �Ҵ�ȴ�.
	������ �ٷ������ heap�� ���α׷��ӿ� ���� �Ҵ�(new)�ǰų� �Ҹ�(delete)�ȴ�.
	���� ���α׷��Ӱ� ���� �� ���ϴ� ũ��� �Ҵ��� �� �ִ� ���̴�.
	����� ������ ������ stack�� �Ҵ�ȴ�.

	int* arr = new int[10];

	*/


	/*
	new & delete
	���� �޸𸮴� Compile�ÿ� stack ������ �Ҵ�ǰ� �Լ��� �������� �� �Ҹ�ȴ�.
	�ݸ� ���� �޸𸮴� Runtime �� ���α׷����� �ǵ���� heap ������ �Ҵ�ǰ� �Ҹ�ȴ�.
	���� ���� �޸𸮸� control �ϱ� ���� ��Ģ�� ���س�������,
	C++������ �Ҵ� �� new �����ڸ� ����ϸ� �Ҹ� �ÿ� delete �����ڸ� ����Ѵ�.
	heap ������ ���� �Ҵ�Ǵ� �޸��� ��� �������� ���α׷��ӿ� ���� �����ǹǷ�,
	����� �����ٸ� �ݵ�� delete�� ���־�� �Ѵ�.
	����� ���� �迭�� delete �ϴ� ��� �迭�̶�� ���� ����ϱ� ���� delete[] �����ڸ� ����ؾ߸� �Ѵ�.
	*/

	/*
	* ���� �Ҵ��� ����ϴ� ����
	* ���� �Ҵ��� Compile�ÿ� stack ������ �޸� �Ҵ� ������
	* ���� �Ҵ��� ���ʿ��� �޸� ������ �������� �ʰ� ������(Runtime)�� �ʿ��Ҷ��� �Ҵ�ǰ� �Ҹ� �޸� ������ ������
	*/
	int* nA = new int;// heap������ �Ҵ�

	*nA = 1;

	delete nA;// heap�������� ����

	//int* nArray = new int[10];// heap������ �Ҵ�
	//int* nArray = new int[10]();// heap������ �Ҵ�
	int* pArray = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};// heap������ �Ҵ�

	for (int i = 0; i < 10; i++)
	{
		printf("nArray[%d]=%d\n", i, pArray[i]);
	}

	delete[] pArray;// heap�������� ����

	{
		// ���� ���� & ���� ����
		int* a = new int(10);
		int* b = new int(20);

		//a = b;// b�� �ּҰ��� a�� �ְڴ�, b�� ����Ű�� �ִ°� a�� ����Ű�ڴ�.<-[���� ����]
		*a = *b;// b�� ����Ű�� �ִ� ���� a�� ����Ű�� ������ ����<-[���� ����]

		delete a;
		delete b;
	}
}