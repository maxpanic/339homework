#include <assert.h>
#include <iostream>
#include "DynArray.h"

DynArray::DynArray()
  : sizeM(0), storageM(new EType[1])
{
  storageM[0] = '0';
}

DynArray::DynArray(const EType *builtin, int sizeA)
  : sizeM(sizeA), storageM(new EType[sizeA])
{
	assert(sizeA != 0);

	for(int i=0;i < sizeM;++i)
		{
			storageM[i] = builtin[i];
		}
}

int DynArray::size() const
{
	return sizeM;
}

EType DynArray::at(int i) const
{
	assert(0 <= i && i < size());
	return storageM[i];
}

void DynArray::set(int i, EType new_value)
{
	assert(0 <= i && i < size());
	storageM[i]=new_value;
}

void DynArray::resize(int new_size)
{
	assert(new_size >= 0);
	EType *storageM2 = new EType [sizeM];
	for(int i=0;i < sizeM;++i)
	{
		storageM2[i] = storageM[i];
	}
	delete[] storageM;
	storageM = new EType[new_size];
	sizeM = new_size;
	for(int i=0; i < sizeM; ++i)
	{
		storageM[i] = storageM2[i];
	}
	delete[] storageM2;
}

DynArray::DynArray(const DynArray& source): sizeM(source.sizeM)
{
	storageM = new EType[sizeM];
	for(int i=0; i < sizeM ; ++i)
		{
			storageM[i] = source.storageM[i];
		}
}

DynArray& DynArray::operator=(const DynArray& rhs)
{
	if ( &rhs != this)
	{
		if ( sizeM != rhs.sizeM)
		{
			delete[] storageM;
			sizeM = rhs.sizeM;
			storageM = new EType[sizeM];
		}
		for (int i =0; i < sizeM; ++i)
		{
			storageM[i] = rhs.storageM[i];
		}
	}
	return *this;
}
DynArray::~DynArray()
{
	delete[] storageM;
	storageM = NULL;
	sizeM = 0;
}
