#pragma once

class Clonable
{
public:
	virtual ~Clonable()
	{
	}

public:
	virtual Clonable* cloner() const = 0;
};

template<typename ClasseMere>
class PointeurClonable
{
public:
	PointeurClonable()
		: pointeur(nullptr)
	{
	}

	PointeurClonable(ClasseMere* lePointeur)
		: pointeur(lePointeur)
	{
	}

	PointeurClonable(const PointeurClonable& pointeurClonable)
	{
		const ClasseMere* const ptr = pointeurClonable;

		if (ptr)
		{
			pointeur = ptr->cloner();
		}
		else
		{
			pointeur = nullptr;
		}
	}

	PointeurClonable(PointeurClonable&& pointeurClonable)
	{
		pointeur = pointeurClonable.pointeur;
		pointeurClonable.pointeur = nullptr;
	}

	~PointeurClonable()
	{
		if (pointeur)
		{
			delete pointeur;
		}
	}

public:
	PointeurClonable& operator=(ClasseMere* lePointeur)
	{
		if (pointeur)
		{
			delete pointeur;
		}

		pointeur = lePointeur;

		return *this;
	}

	PointeurClonable& operator=(const PointeurClonable& pointeurClonable)
	{
		if (pointeur)
		{
			delete pointeur;
		}

		const ClasseMere* const ptr = pointeurClonable;

		if (ptr)
		{
			pointeur = ptr->cloner();
		}
		else
		{
			pointeur = nullptr;
		}

		return *this;
	}

	operator ClasseMere*() const
	{
		return pointeur;
	}

private:
	ClasseMere* pointeur;
};
