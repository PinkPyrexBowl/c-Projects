#ifndef BOUNDEDARRAY_H
#define BOUNDEDARRAY_H
class BoundedArray{
public:
	BoundedArray();
	BoundedArray(int numElements);
	BoundedArray(int numElements, int maxNumElements);
	BoundedArray(BoundedArray& b);
	~BoundedArray();
	int size();
	int capacity();
	double& operator[](int index);
	double& at(int index);
	double* data();
	BoundedArray& operator=(BoundedArray& b);
	void resize(int newSize);
	void push_back(double value);
	void pop_back();
	void insert(int index, double value);
	void erase(int index);
	void clear();
private:
	int MAX_NUM_ELEMENTS = 100;
	int numElements = 0;
	double* elements = nullptr;
};
#endif // !BOUNDEDARRAY_H	
