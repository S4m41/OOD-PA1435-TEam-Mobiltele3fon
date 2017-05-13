#ifndef TWITTERREADER_HPP
#define TWITTERREADER_HPP

#include <string>

struct RoomInfo
{
	std::wstring leftChild   = L" ";
	std::wstring middleChild = L" ";
	std::wstring rightChild  = L" ";
};

class TwitterReader
{
public:
	TwitterReader();
	~TwitterReader();

	RoomInfo GetRoomInfo(std::wstring roomName) const;
private:


};

#endif // !TWITTERREADER_HPP
