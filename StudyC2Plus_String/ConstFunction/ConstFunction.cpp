#include <stdio.h>
#include <vector>

struct stHouse
{
	int m_address;
	int m_Price;
	int m_RoomCnt;
	int m_Size;

	stHouse(int address = 0, int price = 0, int roomcnt = 0, int size = 0)
		:m_address(address), m_Price(price), m_RoomCnt(roomcnt), m_Size(size){}
};

class CHouse
{
public:
	CHouse(stHouse info):m_info(info){}
	~CHouse(){}

public:
	const stHouse& GetHouseInfoRef() const
	{
		return m_info;
	}

	stHouse* const GetHouseInfo() const
	{
		return &m_info;
	}

private:
	stHouse m_info;
};

class CLandlord
{
public:
	CLandlord(){}
	~CLandlord()
	{
		if (vecHouses.size() == 0)
			return;

		for (CHouse* pHouse : vecHouses)
		{
			delete pHouse;
		}
	}

	void BuyHouse(int address, int Price, int RoomCnt, int Size)
	{
		stHouse info(address, Price, RoomCnt, Size);
		CHouse* pHouse = new CHouse(info);
		vecHouses.push_back(pHouse);
	}

	void PrintAllHouse()
	{
		if (vecHouses.size() == 0)
		{
			printf("Have No House!\n");
			return;
		}

		for (int i = 0; i < vecHouses.size(); ++i)
		{
			stHouse* aaa = nullptr;
			const stHouse* info = vecHouses[i]->GetHouseInfo();
			//info = nullptr;
			//info->m_address = 1;
			printf("Address=%d, Price=%d, RoomCnt=%d, Size=%d\n"
				, info->m_address
				, info->m_Price
				, info->m_RoomCnt
				, info->m_Size);
		}
	}

public:
	std::vector<CHouse*> vecHouses;
};

int main()
{
	CLandlord landload;
	bool run = true;

	while (run)
	{
		int input = 0;
		printf("0)Quit 1)Show All House 2)Buy NewHouse : ");
		scanf_s("%d", &input);
		system("cls");
		switch (input)
		{
		case 0:
			run = false;
			break;

		case 1:
			landload.PrintAllHouse();
			break;

		case 2:
			int Address, Price, RoomCnt, Size;
			printf("Address : ");
			scanf_s("%d", &Address);
			printf("Price : ");
			scanf_s("%d", &Price);
			printf("RoomCnt : ");
			scanf_s("%d", &RoomCnt);
			printf("Size : ");
			scanf_s("%d", &Size);
			landload.BuyHouse(Address, Price, RoomCnt, Size);
			break;

		default:
			break;
		}
	}

}
