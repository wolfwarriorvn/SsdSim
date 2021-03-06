#ifndef __NandDevice_h__
#define __NandDevice_h__

#include <memory>
#include <vector>

#include "Nand/NandDeviceDesc.h"
#include "Nand/NandBlock.h"

class NandDevice
{
public:
	NandDevice(U32 blockCount, U32 pagesPerBlock, U32 bytesPerPage);
	NandDevice(NandDevice&& rhs) = default;

public:
	void ReadPage(tBlockInDevice block, tPageInBlock page, U8* const pOutData);

	void WritePage(tBlockInDevice block, tPageInBlock page, const U8* const pInData);

	void EraseBlock(tBlockInDevice block);

private:
	std::unique_ptr<NandDeviceDesc> _Desc;
	std::vector<NandBlock> _Blocks;
};

#endif