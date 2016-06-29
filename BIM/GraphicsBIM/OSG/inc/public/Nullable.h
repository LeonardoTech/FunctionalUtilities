#ifndef __NULLABLE_H__
#define __NULLABLE_H__

template<class T>
class Nullable
{
public:
	Nullable()
	{
		_empty = true;
	}

	bool empty()
	{
		return _empty;
	}

	void operator = (T other)
	{
		set(other);
	}

	void set(T other)
	{
		_value = other;
		_empty = false;
	}

	T& get()
	{
		return _value;
	}

	void setNull()
	{
		_empty = true;
	}

protected:
	T _value;
	bool _empty;
};

#endif // __NULLABLE_H__
