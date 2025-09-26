#pragma once
#include <iostream>

// 전방 선언
class APlayer;
class Items;

class Store
{
public:
	Store() { printf("\"수상한 간판대 주인 : \"이봐! 이 물건들이 도움이 되지 않겠어?? 한 번 둘러보라고!\"\n"); }
	~Store() { printf("\"흐흐... 한 번 잘해보라고!\"\n"); }

	void ShoppingTime(APlayer* InPlayer, Items* InItems);

private:

};

