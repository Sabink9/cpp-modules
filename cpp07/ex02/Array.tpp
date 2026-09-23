template <class T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <class T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <class T>
Array<T>::~Array()
{
	delete[] _data;
}

template <class T>
Array<T>::Array(Array const& other) : _data(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <class T>
Array<T>& Array<T>::operator=(Array const& other)
{
	if (this != &other)
	{
		delete[] _data;
		
		_data = new T[other._size];
		_size = other._size;

		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <class T>
unsigned int Array<T>::size() const
{
	return (_size);
}