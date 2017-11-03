#ifndef __PRODUCT_H__
#define __PRODUCT_H__

class Product
{
public:
	virtual void execute() = 0;
	virtual ~Product();
};

#endif